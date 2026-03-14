#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 0x3f3f3f3f;
int dist[N];
struct edge {
    int u, v, w;
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};
vector<edge> ed;
int n, m;

bool bf(int s) {
    fill(dist, dist + n + 1, INF);
    dist[s] = 0;

    int times{n};
    bool flag{false};
    while (times--) {
        flag = false;
        for (auto& [u, v, w] : ed) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                flag = true;
                dist[v] = dist[u] + w;
            }
        }
        if (flag == false) return flag;
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        ed.emplace_back(u, v, -w);
    }
    if (bf(1)) {
        cout << "Forever love\n";
        return 0;
    }
    int ret{dist[n]};
    if (bf(n)) {
        cout << "Forever love\n";
        return 0;
    }
    cout << min(ret, dist[1]) << "\n";


}