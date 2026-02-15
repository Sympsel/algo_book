#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
const int INF = 2147483647;
using PI = pair<int, int>;
vector<PI> g[N];
int dist[N], cnt[N];
bool st[N];
int n, m;

bool spfa() {
    queue<int> q;
    q.emplace(1);
    st[1] = true;


    while (q.size()) {
        auto u{q.front()}; q.pop();
        st[u] = false;

        for (auto& [v, w] : g[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return true;
                if (!st[v]) {
                    q.emplace(v);
                    st[v] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        cin >> n >> m;
        fill(dist, dist + n + 1, INF);
        fill(st, st + n + 1, false);
        fill(cnt, cnt + n + 1, 0);
        dist[1] = 0;
        for (int i{1}; i <= n; ++i)
            g[i].clear();

        int u, v, w;
        while (m--) {
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            if (w >= 0)
                g[v].emplace_back(u, w);
        }

        if (spfa()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
