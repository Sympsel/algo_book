#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n0, n1, n;
    cin >> n0 >> n1 >> n;
    if (n0 == 0) {
        if (n1 % n || n1 == n) cout << "No Solution";
        else cout << 0 << " " << n;
        return 0;
    } else if (n1 == 0) {
        if (n0 % n || n0 == n) cout << "No Solution";
        else cout << n << " " << 0;
        return 0;
    }
    int diff{n};
    int rx{-1};
    for (int i{2}; i <= n0; ++i) {
        if (n0 % i != 0) continue;
        int x{n0 / i};
        if (x >= n) continue;
        if (n1 % (n - x) || n1 == n - x) continue;
        if (diff > abs(2 * x - n)) {
            rx = x;
            diff = abs(2 * x - n);
        }
    }
    if (rx == -1) cout << "No Solution";
    else cout << rx << " " << (n - rx);
    return 0;
}