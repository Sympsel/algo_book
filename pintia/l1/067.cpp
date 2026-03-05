#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double x, y;
    char ch;
    cin >> x >> ch >> y;
    double k{};
    if (ch == '0') k = 2.455;
    else k = 1.26;

    double ret{k * x};
    cout << fixed << setprecision(2);
    cout << ret << " ";
    if (ret <= y) cout << "^_^";
    else cout << "T_T";

    return 0;
}