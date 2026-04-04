#include <bits/stdc++.h>
using namespace std;

const int N = 207;
const int INF = 0x3f3f3f3f;
int n, m;
int a[N];
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    memset(f, 0x3f, sizeof f);
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        f[u][v] = f[v][u] = min(f[u][v], w);
    }
    for (int i{}; i <= n; ++i) f[i][i] = 0;

    for (int k{}; k <= n; ++k) {
        for (int i{}; i <= n; ++i) {
            for (int j{}; j <= n; ++j) {
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    int T; cin >> T;
    int ret{};
    int st{T};
    int min_w{INF};
    for (int i{1}; i <= T; ++i) {
        cin >> m;
        bool eff{true};

        unordered_set<int> vis;
        for (int j{1}; j <= m; ++j) {
            cin >> a[j];
        }
        if (m != n) {
            eff = false;
            continue;
        }
        a[m + 1] = 0;
        int sum{};
        for (int j{}; j <= m; ++j) {
            int u{a[j]}, v{a[j + 1]};

            if (f[u][v] == INF || vis.count(v)) {
                eff = false;
                break;
            }
            if (v) vis.emplace(v);
            sum += f[u][v];
        }
        if (eff) {
            if (sum < min_w) {
                min_w = sum;
                ret = i;
            }
        } else {
            --st;
        }
    }
    cout << st << "\n";
    cout << ret << " " << min_w;

    return 0;
}
