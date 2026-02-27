#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e3 + 7;
ll a[N][N], f[N][N], g[N][N];
int n, m, k;
const int p = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T >> k;
    for (int i{}; i <= N - 3; ++i) {
        a[i][0] = 1;
        for (int j{1}; j <= i; ++j) {
            a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % k;
        }
    }
    // for (int i{}; i <= 5; ++i) {
    //     for (int j{}; j <= 5; ++j) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i{}; i <= N - 3; ++i) {
        for (int j{}; j <= i; ++j) {
            if (a[i][j] % k == 0) f[i][j] = 1;
            else f[i][j] = 0;
        }
        f[i][i + 1] = f[i][i];
    }

    // for (int i{}; i <= 5; ++i) {
    //     for (int j{}; j <= 5; ++j) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i{}; i <= N - 3; ++i) {
        g[i][0] = f[i][0];
        for (int j{1}; j <= i; ++j) {
            g[i][j] = g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1] + f[i][j];
        }
        g[i][i + 1] = g[i][i];
    }

    // for (int i{}; i <= 5; ++i) {
    //     for (int j{}; j <= 5; ++j) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    while (T--) {
        cin >> n >> m;
        m > n ? m = n : m;
        cout << g[n][m] << "\n";
    }

    return 0;
}