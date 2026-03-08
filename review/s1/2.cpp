#include <bits/stdc++.h>
using namespace std;


const int N = 5004;
int n;
int dist[N];
bool st[N];
vector<pair<int,int>> ed[N];
const int INF = 0x3f3f3f3f;

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int ret{};
    for (int i{1}; i <= n; ++i) {
        int u{};
        for (int j{1}; j <= n; ++j) {
            if (!st[j] && dist[j] < dist[u])
                u = j;
        }
        if (u == 0) return INF;
        st[u] = true;
        ret += dist[u];

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
    if (ret == INF) cout << "orz";
    else cout << ret << "\n";
    return 0;
}