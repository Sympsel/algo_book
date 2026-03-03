#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int INF = 0x3f3f3f3f;
vector<int> g[N];
int n;
int f[N];

int sg(int u) {
    if (f[u] != INF) return f[u];
    unordered_set<int> mp;
    for (auto& v : g[u])
        mp.emplace(sg(v));
    int mex{};
    while (mp.count(mex)) ++mex;
    return f[u] = mex;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(f, 0x3f, sizeof f);
    int m, k; cin >> n >> m >> k;
    int u, v;
    while (m--) {
        cin >> u >> v;
        g[u].emplace_back(v);
    }

    int _, s{};
    while (k--) {
        cin >> _;
        s ^= sg(_);
    }

    if (s) cout << "win\n";
    else cout << "lose\n";

    return 0;
}