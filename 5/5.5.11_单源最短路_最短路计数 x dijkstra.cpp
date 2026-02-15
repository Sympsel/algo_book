#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e6 + 5;
const int p = 1e5 + 3;

vector<int> g[N];
int dist[N], f[N];
bool st[N];
int n, m;

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> q;

    fill(dist, dist + n + 1, INF);
    dist[1] = 0; f[1] = 1;
    q.emplace(0, 1);

    while (q.size()) {
        auto [_, u]{q.top()}; q.pop();
        if (st[u]) continue;
        st[u] = true;

        for (auto& v : g[u]) {
            if (dist[u] + 1 < dist[v]) {
                dist[v] = dist[u] + 1;
                f[v] = f[u];
                q.emplace(dist[v], v);
            } else if (dist[u] + 1 == dist[v]) {
                f[v] = (f[v] + f[u]) % p;
            } else {}
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int u, v;
    while (m--) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dijkstra();

    for (int i{1}; i <= n; ++i)
        cout << f[i] << "\n";

    return 0;
}