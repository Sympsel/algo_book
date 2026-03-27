#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n;
vector<int> ed[N];

int order[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int root{};
    for (int v{1}; v <= n; ++v) {
        int u; cin >> u;
        if (u != -1) {
            ed[u].emplace_back(v);
        } else {
            root = v;
        }
    }
    queue<int> q;
    int cnt{};
    q.emplace(root);
    order[root] = 1;
    while (q.size()) {
        int sz(q.size());
        ++cnt;
        while (sz--) {
            auto& u{q.front()};
            for (auto& v : ed[u]) {
                q.emplace(v);
                order[v] = order[u] + 1;
            }
            q.pop();
        }
    }
    cout << cnt << "\n";
    bool is_first{true};
    for (int i{1}; i <= n; ++i) {
        if (order[i] == cnt) {
            if (is_first) is_first = false;
            else cout << " ";
            cout << i;
        }
    }
    return 0;
}
