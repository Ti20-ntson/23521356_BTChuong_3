#include<bits/stdc++.h>

using namespace std;

pair<long long, long long> Rut_Gon(long long x, long long y) {
    long long cc = __gcd(x, y);
    x /= cc;
    y /= cc;
    return {x, y};
}

int main() {
    pair<long long, long long> Ans;
    long long x1, y1, x2, y2;
    cout << "Nhap phan so thu nhat : ";
    cin >> x1 >> y1;
    cout << endl;
    cout << "Nhap phan so thu hai : ";
    cin >> x2 >> y2;
    cout << endl;
    Ans = Rut_Gon(x1 * y2 + x2 * y1, y1 * y2);
    cout << "Tong cua hai phan so :" << Ans.first << " " << Ans.second << endl;
    Ans = Rut_Gon(x1 * y2 - x2 * y1, y1 * y2);
    cout << "Hieu cua hai phan so :" << Ans.first << " " << Ans.second << endl;
    Ans = Rut_Gon(x1 * x2, y1 * y2);
    cout << "Tich cua hai phan so :" << Ans.first << " " << Ans.second << endl;
    Ans = Rut_Gon(x1 * y2, x2 * y1);
    cout << "Thuong cua hai phan so" << Ans.first << " " << Ans.second << endl;
}

