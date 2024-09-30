#include<bits/stdc++.h>

using namespace std;

pair<int, int> Rut_Gon(int x, int y) {
    int cc = __gcd(x, y);
    x /= cc;
    y /= cc;
    return {x, y};
}

int main() {
    cout << "Phan so can rut gon : ";
    int x, y;
    cin >> x >> y;
    pair<int, int> Ans = Rut_Gon(x, y);
    cout << Ans.first << " " << Ans.second;
}


