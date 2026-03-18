#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
using ll = long long;
ll a[N][N];
ll f[N][N], g[N][N];
int n, m;
const ll INF = -1e16;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i{}; i <= n + 1; ++i) {
        for (int j{}; j <= m + 1; ++j) {
            f[i][j] = g[i][j] = INF;
        }
    }
    f[0][1] = 0;
    for (int j{1}; j <= m; ++j) {

        for (int i{1}; i <= n; ++i) {
            f[i][j] = max({f[i][j - 1], g[i][j - 1], f[i - 1][j]}) + a[i][j];
        }
        for (int i{n}; i >= 1; --i) {
            g[i][j] = max({f[i][j - 1], g[i][j - 1], g[i + 1][j]}) + a[i][j];
        }
    }

    cout << f[n][m] << "\n";


    return 0;
}