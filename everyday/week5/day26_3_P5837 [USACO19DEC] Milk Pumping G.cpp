#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int n, m;
const int M = 1e6;
int f[N][N]; // 流量
using pii = pair<int, int>;
vector<pii> ed[N]; // cost
const int INF = 0x3f3f3f3f;

bool st[N];
int dist[N];

// 返回当最小流量为x时的最小花费
int dijkstra(int x) {
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, 1);
    while (q.size()) {
        auto [_, u]{q.top()}; q.pop();
        if (st[u]) continue;
        st[u] = true;

        for (auto& [v, w] : ed[u]) {
            int c{f[u][v]};
            if (c < x) continue;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.emplace(dist[v], v);
            }
        }
    }
    return dist[n];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int u, v, w, c;
    while (m--) {
        cin >> u >> v >> w >> c;
        f[u][v] = f[v][u] = c;
        ed[u].emplace_back(v, w);
        ed[v].emplace_back(u, w);
    }

    int ret{};
    for (int i{1}; i <= 1000; ++i) {
        ret = max(ret, M * i / dijkstra(i));
    }
    cout << ret << "\n";
    return 0;
}
