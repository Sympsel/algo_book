#include <bits/stdc++.h>
using namespace std;

const int N = 1007;
int v[N], w[N], n, m;
int f[N][N];
const int INF = -0x3f3f3f3f;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i{1}; i <= n; ++i)
        cin >> v[i] >> w[i];

    for (int i{1}; i <= n; ++i) {
        for (int j{}; j <= m; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    cout << f[n][m] << "\n";


    memset(f, INF, sizeof f);
    f[0][0] = 0;
    for (int i{1}; i <= n; ++i) {
        for (int j{}; j <= m; ++j) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }

    cout << max(f[n][m], 0) << "\n";

    return 0;
}