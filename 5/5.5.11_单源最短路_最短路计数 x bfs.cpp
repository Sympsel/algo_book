#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int p = 1e5 + 3;
const int INF = 0x3f3f3f3f;
int n, m;
int f[N];
int dist[N];
vector<int> g[N];

void bfs() {
    fill(dist, dist + n + 1, INF);
    f[1] = 1;
    dist[1] = 0;

    queue<int> q;
    q.emplace(1);

    while (q.size()) {
        auto u{q.front()}; q.pop();

        for (auto& v : g[u]) {
            if (dist[u] + 1 < dist[v]) {
                f[v] = f[u];
                dist[v] = dist[u] + 1;
                q.emplace(v);
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
    bfs();
    for (int i{1}; i <= n; ++i)
        cout << f[i] << "\n";
    return 0;
}
