#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using pii = pair<int, int>;
vector<pii> ed[N];

int dist[N];
bool st[N];
const int INF = 0x3f3f3f3f;
int n, m ,s;
priority_queue<pii, vector<pii>, greater<pii>> q;

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    q.emplace(0, s);
    while (q.size()) {
        auto [_, u]{q.top()}; q.pop();
        if (st[u]) continue;
        st[u] = true;
        for (auto [v, w] : ed[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.emplace(dist[v], v);
            }
        }
    }
    for (int i{1}; i <= n; ++i) cout << dist[i] << " ";
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

    return 0;
}
