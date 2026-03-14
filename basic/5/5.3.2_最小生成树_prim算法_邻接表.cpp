#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int INF = 0x3f3f3f3f;
using ed = pair<int, int>;
vector<ed> edges[N];
int dist[N];
bool st[N];

int n, m;

int prim() {
    fill(dist, dist + n + 1, INF);
    dist[1] = 0;

    int ret{};
    for (int i{1}; i <= n; ++i) {
        int t{};
        for (int j{1}; j <= n; ++j)
            if (!st[j] && dist[j] < dist[t])
                t = j;

        if (dist[t] == INF) return INF;
        st[t] = true;
        ret += dist[t];

        for (auto& [v, w] : edges[t])
            if (!st[v])
                dist[v] = min(dist[v], w);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; int u, v, w;
    for (int i{1}; i <= m; ++i) {
        cin >> u >> v >> w;
        edges[u].emplace_back(v, w);
        edges[v].emplace_back(u, w);
    }

    int ret = prim();
    if (ret == INF) cout << "orz\n";
    else cout << ret << "\n";
    return 0;
}
