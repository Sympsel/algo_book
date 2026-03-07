#include <bits/stdc++.h>
using namespace std;

int sum(int x) {
    int ret{};
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    int x, y, s, d;
    while (t--) {
        cin >> x >> y;
        s = sum(x); d = sum(y);
        if (y % s == 0 && x % d == 0 || y % s != 0 && x % d != 0) {
            if (x > y) {
                cout << "A\n";
            } else cout << "B\n";
        } else if (y % s == 0) cout << "B\n";
        else cout << "A\n";
    }

    return 0;
}