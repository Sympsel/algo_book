#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
int n, p, m;
using pii = pair<int, int>;
vector<pii> ed[N];
int a[N];
bool st[N];
int dist[N];
const int INF{0x3f3f3f3f};

int dijkstra(int s) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
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
    int sum{};
    for (int i{1}; i <= n; ++i) {
        if (dist[a[i]] == INF) return INF;
        sum += dist[a[i]];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> p >> m;
    for (int i{1}; i <= n; ++i) cin >> a[i];

    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        ed[u].emplace_back(v, w);
        ed[v].emplace_back(u, w);
    }
    int ret{INF};
    for (int i{1}; i <= p; ++i) {
        ret = min(ret, dijkstra(i));
    }
    cout << ret << "\n";
    return 0;
}