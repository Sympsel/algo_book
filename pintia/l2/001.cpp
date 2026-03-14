#include <bits/stdc++.h>
using namespace std;

const int N = 505;

vector<pair<int, int>> g[N];
bool st[N];
int a[N];

int n, from, to;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m >> from >> to;
    for (int i{}; i < n; ++i) cin >> a[i];
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    queue<int> q;
    q.emplace(from);
    st[from] = true;

    int ret{};
    int cnt{};
    bool fd{};
    while (q.size()) {
        int t(q.size());
        while (t--) {
            auto v{q.front()}; q.pop();
            ret += a[v];
            if (v == to) {
                ++cnt;
                fd = true;
            }
            if (!st[v]) {
                q.emplace(v);
                st[v] = true;
            }
        }
        if (fd) break;
    }

    cout << ret << "\n";
    return 0;
}
