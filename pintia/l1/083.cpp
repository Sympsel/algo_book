#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    if (x >= a && y >= a) {
        cout << x << "-Y" << " " << y << "-Y\n";
        cout << "huan ying ru guan";
    } else if (x < a && y < a) {
        cout << x << "-N" << " " << y << "-N\n";
        cout << "zhang da zai lai ba";
    } else if (x >= b && y < a) {
        cout << x << "-Y" << " " << y << "-Y\n";
        cout << "qing 1 zhao gu hao 2";
    } else if (x < a && y >= b) {
        cout << x << "-Y" << " " << y << "-Y\n";
        cout << "qing 2 zhao gu hao 1";
    } else if (x >= a) {
        cout << x << "-Y" << " " << y << "-N\n";
        cout << "1: huan ying ru guan";
    } else if (y >= a) {
        cout << x << "-N" << " " << y << "-Y\n";
        cout << "2: huan ying ru guan";
    }

    return 0;
}