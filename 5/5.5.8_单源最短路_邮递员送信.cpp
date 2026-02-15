#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 2147483647;
using ps = pair<int, int>;

int n, m;
vector<ps> g1[N], g2[N];
int d1[N], d2[N];
bool st1[N], st2[N];

void dijkstra(vector<ps> g[N], int* dist, bool* st) {
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;
    int times{n - 1};
    while (times--) {
        int u{};
        for (int i{1}; i <= n; ++i)
            if (!st[i] && dist[i] < dist[u])
                u = i;
        if (u == 0) break;
        st[u] = true;
        for (auto& [v, w] : g[u])
            dist[v] = min(dist[v], dist[u] + w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int u, v, w;
    for (int i{1}; i <= m; ++i) {
        cin >> u >> v >> w;
        g1[u].emplace_back(v, w);
        g2[v].emplace_back(u, w);
    }

    dijkstra(g1, d1, st1);
    dijkstra(g2, d2, st2);
    int ret{};
    for (int i{1}; i <= n; ++i)
        ret += d1[i] + d2[i];
    cout << ret;

    return 0;
}