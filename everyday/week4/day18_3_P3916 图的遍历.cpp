#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n, m;
vector<int> ed[N];
int a[N];
bool st[N];

void bfs(int x, int _max) {
    queue<int> q;
    q.emplace(x);
    a[x] = _max;
    st[x] = true;

    while (q.size()) {
        auto& u{q.front()}; q.pop();

        for (auto& v : ed[u]) {
            if (st[v]) continue;
            q.emplace(v);
            a[v] = _max;
            st[v] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int u, v;
    for (int i{1}; i <= m; ++i) {
        cin >> u >> v;
        // 反向求可以到达u的节点
        ed[v].emplace_back(u);
    }

    for (int i{n}; i >= 1; --i) {
        if (st[i]) continue;
        bfs(i, i);
        a[i] = i;
        st[i] = true;
    }
    for (int i{1}; i <= n; ++i)
        cout << a[i] << " \n"[i == n];

    return 0;
}
