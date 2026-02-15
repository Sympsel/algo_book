#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 2e5 + 5;
const int INF = (unsigned int)(1 << 31) - 1;
vector<pair<int, int>> ed[N];
int n, m, s;
bool st[N];
int dist[N];

void dijkstra() {
    fill(dist, dist + n + 1, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> h;
    h.emplace(0, s);

    while (h.size()) {
        auto [_, u]{h.top()}; h.pop();

        if (st[u]) continue;
        st[u] = true;
        for (auto& [v, w] : ed[u]) {
            dist[v] = min(dist[v], dist[u] + w);
            h.emplace(dist[v], v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        ed[u].emplace_back(v, w);
    }

    dijkstra();
    for (int i{1}; i <= n; ++i)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}
