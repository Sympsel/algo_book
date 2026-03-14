#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 5e5 + 5;
using ll = long long;
const int INF = (unsigned int)(1 << 31) - 1;
vector<pair<int, int>> ed[N];
int n, m, s;
bool st[N];
ll dist[N];

bool dijkstra() {
    fill(dist, dist + n + 1, INF);
    dist[s] = 0;

    int times{n - 1};

    while (times--) {
        int u{};
        for (int j{1}; j <= n; ++j)
            if (!st[j] && dist[j] < dist[u])
                u = j;

        if (u == 0) return false;
        st[u] = true;
        for (auto& [v, w] : ed[u])
            dist[v] = min(dist[v], dist[u] + w);
    }
    return true;
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

    if (dijkstra()) {
        for (int i{1}; i <= n; ++i)
        cout << dist[i] << " ";
        cout << "\n";
    } else cout << INF << "\n";

    return 0;
}
