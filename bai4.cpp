#include<bits/stdc++.h>

using namespace std;

#define PI 3.14159265358979323846

double Sin(double x) {
    double tmp = x;
    double sinx = tmp; // Kết quả ban đầu là hạng tử đầu tiên
    int n = 1;

    while (fabs(tmp) >= 0.00001) { // Độ chính xác 0.00001
        tmp = (-tmp * x * x) / ((2 * n) * (2 * n + 1)); // Tính hạng tử tiếp theo
        sinx += tmp; // Cộng hạng tử mới vào tổng
        n++;
    }

    return sinx;
}

int main() {
    double x_degree;
    cout << "Nhap gia tri cua x (don vi do tu 0 -> 180): ";
    cin >> x_degree;

    // Chuyển đổi từ độ sang radian
    double x_radian = x_degree * PI / 180.0;

    // Tính giá trị sin(x) với x theo radian
    double result = Sin(x_radian);
    cout << "Gia tri cua sin(" << x_degree << " do) la: " << result << endl;

    return 0;
}
