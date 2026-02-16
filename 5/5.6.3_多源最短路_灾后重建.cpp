#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int INF = 0x3f3f3f3f;
int f[N][N];
int ts[N];
int n;

int u, v, w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;
    memset(f, 0x3f, sizeof f);
    for (int i{}; i < n; ++i) {
        cin >> ts[i];
        f[i + 1][i + 1] = 0;
    }

    while (m--) {
        cin >> u >> v >> w;
        f[u][v] = f[v][u] = min(f[u][v], w);
    }

    int q; cin >> q;
    int s, d, t;
    int k{};
    while (q--) {
        cin >> s >> d >> t;
        if (ts[s] > t || ts[d] > t) {
            cout << "-1\n";
            continue;
        }

        while (k < n && ts[k] <= t) {
            for (int i{}; i < n; ++i)
                for (int j{}; j < n; ++j)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            ++k;
        }

        if (f[s][d] == INF) cout << "-1\n";
        else cout << f[s][d] << "\n";
    }


    return 0;
}
