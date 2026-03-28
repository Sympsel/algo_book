#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
// 记录入度
int in[N];
int depth[N];
int n;
vector<int> ed[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int u{1}; u <= n; ++u) {
        int k; cin >> k;
        for (int j{1}; j <= k; ++j) {
            int v; cin >> v;
            ed[u].emplace_back(v);
            ++in[v];
        }
    }
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    int root{};
    for (int i{1}; i <= n; ++i) {
        if (in[i] == 0) {
            root = i;
            break;
        }
    }
    queue<int> q;
    q.emplace(root);
    while (q.size()) {
        int sz(q.size());
        while (sz--) {
            auto& u{q.front()};
            for (auto& v : ed[u]) {
                depth[v] = depth[u] + 1;
                q.emplace(v);
            }
            q.pop();
        }
    }
    int ret{}, _max{};
    for (int i{1}; i <= n; ++i) {
        if (_max < depth[i]) {
            _max = depth[i];
            ret  = i;
        }
    }
    cout << ret << "\n";
    return 0;
}
