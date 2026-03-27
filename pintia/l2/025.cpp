#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
int n, m;
int uf[N];
bool mask[N];
vector<pair<int, int>> ed;

inline int fd(int x) {
    return x == uf[x] ? x : uf[x] = fd(uf[x]);
}

inline void un(int x, int y) {
    int fx{fd(x)}, fy{fd(y)};
    if (fx != fy) {
        uf[fx] = fy;
    }
}

bool query() {
    int nums; cin >> nums;
    memset(mask, 0, sizeof mask);
    for (int i{1}; i <= n; ++i) uf[i] = i;
    for (int i{1}; i <= nums; ++i) {
        int _; cin >> _;
        mask[_] = true;
    }
    for (auto& [u, v] : ed) {
        if (mask[u] || mask[v]) continue;
        un(u, v);
    }

    int cnt{};
    for (int i{1}; i <= n; ++i) {
        if (uf[i] == i && !mask[i]) ++cnt;
    }
    return cnt == n - nums;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i{}; i < m; ++i) {
        int u, v; cin >> u >> v;
        ed.emplace_back(u, v);
    }

    int t; cin >> t;
    while (t--) {
        if (query()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
