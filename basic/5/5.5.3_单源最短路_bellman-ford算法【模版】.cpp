#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 5e5 + 5;
const int INF = 2147483647;
int n, m, s;
int dist[N];
struct edge {
    int u, v, w;

    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};
vector<edge> ed;

void bellman_ford() {
    fill(dist, dist + n + 1, INF);
    dist[s] = 0;

    for (int i{1}; i < n; ++i) {
        bool flag = false;

        for (auto& [u, v, w] : ed) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                flag = true;
                dist[v] = dist[u] + w;
            }
        }
        if (!flag) break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s;


    int u, v, w;
    for (int i{1}; i <= m; ++i) {
        cin >> u >> v >> w;
        ed.emplace_back(u, v, w);
    }

    bellman_ford();

    for (int i{1}; i <= n; ++i)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}
