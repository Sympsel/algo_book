#include <bits/stdc++.h>
using namespace std;

const int N = 103;
const int M = 53;
int n, m, s;
int a[M][M];
int f[N][M][M];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i{1}; i <= n; ++i)
        for (int j{1}; j <= m; ++j)
            cin >> a[i][j];

    s = m + n;
    for (int k{2}; k <= s; ++k) {
        for (int i1{1}; i1 <= n; ++i1) {
            for (int i2{1}; i2 <= n; ++i2) {
                if (i1 == i2 && k != n + m) continue;
                int j1{k - i1}, j2{k - i2};
                if (j1 < 1 || j1 > m || j2 < 1 || j2 > m) continue;
                int& t{f[k][i1][i2]};
                t = max(f[k - 1][i1 - 1][i2 - 1], t);
                t = max(f[k - 1][i1][i2 - 1], t);
                t = max(f[k - 1][i1 - 1][i2], t);
                t = max(f[k - 1][i1][i2], t);
                t += a[i1][j1] + a[i2][j2];
            }
        }
    }
    cout << f[s][n][n] << "\n";

    return 0;
}
