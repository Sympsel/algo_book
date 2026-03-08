#include <bits/stdc++.h>
using namespace std;

int n, m, s;
const int INF = 2147483647;
const int N = 1e4 + 4;

vector<pair<int, int>> ed[N];
int dist[N];
bool st[N];

void dijkstra() {
    for (int i{}; i <= n; ++i) dist[i] = INF;
    dist[s] = 0;

    for (int i{}; i < n - 1; ++i) {
        int u{};
        for (int j{1}; j <= n; ++j) {
            if (!st[j] && dist[j] < dist[u])
                u = j;
        }
        st[u] = true;

        for (auto& [v, w] : ed[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i{1}; i <= n; ++i) {
        cout << dist[i] << " ";
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

    return 0;
}