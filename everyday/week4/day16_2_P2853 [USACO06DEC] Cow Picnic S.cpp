#include <bits/stdc++.h>
using namespace std;

const int K = 103;
const int N = 1005;
vector<int> ed[N];
int s[K];
int k, n, m;
bool st[N];
int cnt[N];

void dfs(int u) {
    ++cnt[u];
    st[u] = true;

    for (auto& v : ed[u]) {
        if (st[v]) continue;
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k >> n >> m;
    for (int i{1}; i <= k; ++i) cin >> s[i];
    int u, v;
    while (m--) {
        cin >> u >> v;
        ed[u].emplace_back(v);
    }
    for (int i{1}; i <= k; ++i) {
        memset(st, 0, sizeof st);
        dfs(s[i]);
    }

    int ret{};
    for (int i{1}; i <= n; ++i) {
        if (cnt[i] == k) ++ret;
    }
    cout << ret << "\n";

    return 0;
}
