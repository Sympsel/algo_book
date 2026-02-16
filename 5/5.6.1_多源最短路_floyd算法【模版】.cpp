#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;
int f[N][N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    memset(f, 0x3f, sizeof f);
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = min(f[u][v], w);
    }
    for (int i{1}; i <= n; ++i) f[i][i] = 0;

    for (int k{1}; k <= n; ++k) {
        for (int i{1}; i <= n; ++i) {
            for (int j{1}; j <= n; ++j) {
                int& t{f[i][j]};
                // if (f[i][k] != INF && f[k][j] != INF)
                t = min(t, f[i][k] + f[k][j]);
            }
        }
    }
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n; ++j)
            cout << f[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
