#include <bits/stdc++.h>
using namespace std;

const int INF = 2147483647;
const int N = 2e3 + 5;
struct edge {
    int u, v, w;
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};
vector<edge> ed;
int n, m;
int dist[N];

bool bf() {
    int times{n};
    bool flag = false;
    while (times--) {
        flag = false;
        for (auto& [u, v, w] : ed) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                flag = true;
                dist[v] = dist[u] + w;
            }
        }
        if (!flag) return false;
    }

    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    int u, v, w;
    while (T--) {
        cin >> n >> m;
        while (m--) {
            cin >> u >> v >> w;
            ed.emplace_back(u, v, w);
            if (w >= 0)
                ed.emplace_back(v, u, w);
        }
        fill(dist, dist + n + 1, INF);
        dist[1] = 0;

        if (bf()) cout << "YES\n";
        else cout << "NO\n";
        ed.clear();
    }

    return 0;
}
