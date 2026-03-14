#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;
int f[N][N];
int g[N][N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> n >> m;
    memset(f, 0x3f, sizeof f);
    memset(g, 0x3f, sizeof g);
    for (int i{1}; i <= n; ++i)
        g[i][i] = f[i][i] = 0;

    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = f[u][v] = f[v][u] = min(f[u][v], w);
    }

    int ret{INF};
    for (int k{1}; k <= n; ++k) {
        for (int i{1}; i < k; ++i) {
            for (int j{i + 1}; j < k; ++j) {
                if (f[i][j] == INF || g[i][k] == INF || g[k][j] == INF)
                    continue;
                ret = min(ret, f[i][j] + g[i][k] + g[k][j]);
            }
        }

        for (int i{1}; i <= n; ++i) {
            for (int j{1}; j <= n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    if (ret == INF) cout << "No solution.\n";
    else cout << ret;

    return 0;
}