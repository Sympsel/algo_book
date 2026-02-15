#include <bits/stdc++.h>
using namespace std;

const int N = 103;
const float INF = 1e15;
int n, m, s, t;

struct node {
    int x, y;
} a[N];
float dist[N];
bool st[N];

using pif = pair<int, float>;
using pfi = pair<float, int>;
vector<pif> g[N];

float ret{};
float dijkstra() {
    priority_queue<pfi, vector<pfi>, greater<pfi>> q;

    fill(dist, dist + n + 1, INF);
    dist[s] = 0;
    q.emplace(0, s);

    while (q.size()) {
        auto [_, u]{q.top()}; q.pop();
        if (u == t) return dist[t];
        if (st[u]) continue;
        st[u] = true;

        for (auto& [v, w] : g[u]) {
            dist[v] = min(dist[v], dist[u] + w);
            q.emplace(dist[v], v);
        }
    }

    return dist[t];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{1}; i <= n; ++i)
        cin >> a[i].x >> a[i].y;
    cin >> m; int i1, i2;
    while (m--) {
        cin >> i1 >> i2;
        auto& [x1, y1]{a[i1]};
        auto& [x2, y2]{a[i2]};
        float w(sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
        g[i1].emplace_back(i2, w);
        g[i2].emplace_back(i1, w);
    }
    cin >> s >> t;
    cout << std::fixed << std::setprecision(2) << dijkstra() << "\n";
    return 0;
}
