#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;
vector<pair<int, int>> ed[N];
int n;
int dist[N];
bool st[N];
const int INF{0x3f3f3f3f};

int prim() {
    int ret{};
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i{1}; i <= n; ++i) {
        int u{};
        for (int j{1}; j <= n; ++j) {
            if (!st[j] && dist[j] < dist[u]) u = j;
        }
        if (u == 0) return INF;
        ret += dist[u];
        st[u] = true;
        for (auto& [v, w] : ed[u]) {
            dist[v] = min(dist[v], w);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        ed[u].emplace_back(v, w);
        ed[v].emplace_back(u, w);
    }
    int ret{prim()};
    if (ret == INF) cout << "orz\n";
    else cout << ret << "\n";
    return 0;
}