#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int n, m, k;
using ll = long long;
ll a[N][N];
ll f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= m; ++j) {
           f[i][j] = a[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }

    ll ma{-0x3f3f3f3f};
    int u{}, v{};
    for (int i{1}; i <= n - k + 1; ++i) {
        for (int j{1}; j <= m - k + 1; ++j) {
            ll cur{f[i + k - 1][j + k - 1] + f[i - 1][j - 1] - f[i + k - 1][j - 1] - f[i - 1][j + k - 1]};
            if (ma < cur) {
                ma = cur;
                u = i; v = j;
            }
        }
    }
    cout << u << " " << v << "\n";

    return 0;
}