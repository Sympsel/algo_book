#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 5e5 + 5;
const int INF = 2147483647;
int n, m, s;
int dist[N];

vector<pair<int, int>> g[N];
bool st[N];

void spfa() {
    fill(dist, dist + n + 1, INF);
    dist[s] = 0;

    queue<int> q;
    q.emplace(s);
    st[s] = true;

    while (q.size()) {
        auto u{q.front()}; q.pop();
        st[u] = false;

        for (auto& [v, w] : g[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (!st[u]) {
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

    cin >> n >> m >> s;


    int u, v, w;
    for (int i{1}; i <= m; ++i) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }
    spfa();

    for (int i{1}; i <= n; ++i)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}
