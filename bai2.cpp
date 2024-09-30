#include<bits/stdc++.h>

using namespace std;

bool Compare(int x1, int y1, int x2, int y2) {
    return x1 * y2 >= x2 * y1;
}

int main() {
    int x1, y1, x2, y2;
    cout << "Nhap phan so thu nhat : ";
    cin >> x1 >> y1;
    cout << endl;
    cout << "Nhap phan so thu hai : ";
    cin >> x2 >> y2;
    cout << endl;
    cout << "Phan so lon nhat la : ";

    if (Compare(x1, y1, x2, y2))
        cout << x1 << '/' << y1;
    else cout << x2 << '/' << y2;
}

