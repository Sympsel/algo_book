#include <bits/stdc++.h>
using namespace std;

const int N = 1507;
vector<pair<int, int>> ed[N];
int dist[N];
int n, m;
const int INF = -0x3f3f3f3f;

void bellman_ford() {
    for (int i{1}; i <= n; ++i) dist[i] = INF;
        dist[1] = 0;

    for (int i{1}; i < n; ++i) {
        int flag{};
        for (int u{1}; u <= n; ++u) {
            if (dist[u] == INF) continue;
            for (auto [v, w] : ed[u]) {
                if (dist[u] + w > dist[v]) {
                    flag = true;
                    dist[v] = dist[u] + w;
                }
            }
        }
        if (!flag) return;
    }
}

bool st[N];
void spfa() {
    for (int i{}; i <= n; ++i) dist[i] = INF;
    dist[1] = 0;
    queue<int> q;
    q.emplace(1);
    st[1] = true;
    while (q.size()) {
        int u{q.front()}; q.pop();
        st[u] = false;
        for (auto& [v, w] : ed[u]) {
            if (dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
                if (!st[v]) {
                    q.emplace(v);
                    st[v] = true;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        ed[u].emplace_back(v, w);
    }

    // bellman_ford();
    spfa();
    if (dist[n] == INF) cout << "-1\n";
    else cout << dist[n] << "\n";

    return 0;
}
