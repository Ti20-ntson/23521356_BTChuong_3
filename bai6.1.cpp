#include<bits/stdc++.h>

/// Thuật toán Hashing:
/// Mã sử dụng kỹ thuật băm để tìm tất cả các vị trí xuất hiện của chuỗi P
/// trong chuỗi T. Chuỗi P có thể được xem như một mẫu, và chuỗi T là chuỗi
/// mà chúng ta muốn tìm mẫu này.

typedef long long ll;

const int base = 31;
const ll MOD = 1000000003;
const ll maxn = 1000111;

using namespace std;

ll POW[maxn], hashT[maxn], T[maxn], P[maxn];
int lenT, lenP;
/// thuật toán được sử dụng là thuật toán Hash
/// nguồn tham khảo : https://wiki.vnoi.info/algo/string/hash
/// Ý tưởng là lần lượt so sánh các đoạn con liên tiếp của mảng đầu tiên với mảng thứ hai
/// giống như việc ta lần lượt ướm thử từng bộ đồ


// Hàm lấy giá trị băm của đoạn con chuỗi T từ vị trí i đến j
ll getHashT(int i,int j) {
     // Tính giá trị băm của đoạn con từ i đến j trong T bằng cách sử dụng phép trừ và lũy thừa
    return (hashT[j] - hashT[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}


int main() {
    // Nhập độ dài của chuỗi P và T
    cin >> lenP >> lenT;

    // Nhập giá trị của chuỗi P
    for (int i = 1; i <= lenP; i++)
        cin >> P[i];

    // Nhập giá trị của chuỗi T
    for (int i = 1; i <= lenT; i++)
        cin >> T[i];

    // Khởi tạo POW[0] = 1 (lũy thừa đầu tiên của base)
    POW[0] = 1;

    // Tính lũy thừa của base lần lượt cho các chỉ số từ 1 đến lenT
    for (int i = 1; i <= lenT; i++)
        POW[i] = (POW[i - 1] * base) % MOD;

    // Tính giá trị băm của chuỗi T bằng phương pháp băm cộng dồn
    for (int i = 1; i <= lenT; i++)
        hashT[i] = (hashT[i - 1] * base + T[i] + 1) % MOD;

    // Tính giá trị băm của chuỗi P
    ll hashP = 0;
    for (int i = 1; i <= lenP; i++)
        hashP = (hashP * base + P[i] + 1) % MOD;

    // Vector lưu các vị trí xuất hiện của chuỗi P trong chuỗi T
    vector<int> V;

    // Duyệt qua từng đoạn con trong chuỗi T có độ dài bằng lenP
    for (int i = 1; i <= lenT - lenP + 1; i++) {
        // Nếu giá trị băm của đoạn con trong T bằng với giá trị băm của P thì lưu vị trí
        if (hashP == getHashT(i, i + lenP - 1))
            V.push_back(i - 1); // Lưu vị trí bắt đầu của đoạn khớp (giảm 1 để đúng với chỉ số bắt đầu từ 0)
    }

    // In ra số lượng vị trí tìm thấy
    cout << V.size() << endl;

    // In ra các vị trí của chuỗi P xuất hiện trong chuỗi T
    for (int v : V)
        cout << v << " ";

    return 0;
}

