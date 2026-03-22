#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
const int M = 2e5 + 7;
int n, m;
vector<int> ed[N];
vector<int> ed_re[N];
int s, t;
bool st[N];
bool st_re[N];
bool valid[N];

int ret;

void check() {
    queue<int> q;
    q.emplace(t);
    st_re[t] = true;
    while (q.size()) {
        auto u{q.front()}; q.pop();
        for (auto v : ed_re[u]) {
            if (st_re[v]) continue;
            q.emplace(v);
            st_re[v] = true;
        }
    }

    for (int i{1}; i <= n; ++i) {
        valid[i] = true;
        for (auto v : ed[i]) {
            if (!st_re[v]) {
                valid[i] = false;
                break;
            }
        }
    }
}

void bfs() {
    if (!valid[s]) {
        cout << "-1\n";
        return;
    }
    queue<int> q;
    q.emplace(s);
    st[s] = true;
    while (q.size()) {
        int sz(q.size());
        ++ret;
        while (sz--) {
            auto u{q.front()}; q.pop();
            for (auto v : ed[u]) {
                if (v == t) {
                    cout << ret << "\n";
                    return;
                }
                if (st[v] || !valid[v]) continue;
                q.emplace(v);
                st[v] = true;
            }
        }
        if (ret > n - 1) {
            cout << "-1\n";
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int u, v;
    while (m--) {
        cin >> u >> v;
        ed[u].emplace_back(v);
        ed_re[v].emplace_back(u);
    }
    cin >> s >> t;
    check();
    bfs();

    return 0;
}