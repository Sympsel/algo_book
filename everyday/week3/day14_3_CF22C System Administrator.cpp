#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, v;
    cin >> n >> m >> v;
    if (m > (n - 1) * (n - 2) / 2 + 1 || m < n - 1) {
        cout << "-1\n";
        return 0;
    }
    int u{1};
    if (u == v) {
        if (u == n) u = 0;
        else ++u;
    }

    for (int i{1}; i <= n; ++i) {
        if (i != v) {
            cout << i << " " << v << "\n";
            m--;
        }
    }

    for (int i{1}; i <= n; ++i) {
        if (i == u || i == v) continue;
        for (int j{i + 1}; j <= n; ++j) {
            if (m == 0) return 0;
            if (j == u || j == v) continue;
            cout << i << " " << j << "\n";
            m--;
        }
    }
    return 0;
}