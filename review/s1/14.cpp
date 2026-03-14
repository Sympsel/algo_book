#include <bits/stdc++.h>
using namespace std;

const int N = 103;
using ll = long long;
const int INF = 0x3f3f3f3f;
ll f[N][N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    int u, v, w;
    memset(f, 0x3f, sizeof f);
    for (int i{1}; i <= n; ++i) {
        f[i][i] = 0;
    }
    while (m--) {
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = min(f[u][v], 1ll * w);
    }

    for (int k{1}; k <= n; ++k) {
        for (int i{1}; i <= n; ++i) {
            for (int j{1}; j <= n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n; ++j) {
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}