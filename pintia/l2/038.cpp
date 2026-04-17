#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
int n;
int a[N];
int in[N];
vector<int> ed[N];
vector<int> path;
vector<int> ret;
bool st[N];

void dfs(int u) {
    if (ret.size() < path.size()) {
        ret = path;
    }

    for (auto v : ed[u]) {
        if (st[v]) continue;
        st[v] = true;
        path.emplace_back(v);
        dfs(v);
        path.pop_back();
        st[v] = false;
    }

}

int main() {
    cin >> n;
    for (int u{}; u < n; ++u) {
        int m; cin >> m;
        for (int j{}; j < m; ++j) {
            int v; cin >> v;
            ++in[v];
            ed[u].emplace_back(v);
        }
    }
    for (int i{}; i < n; ++i) {
        sort(ed[i].begin(), ed[i].end());
    }
    int s{};
    for (int i{}; i < n; ++i) {
        if (in[i] == 0) {
            s = i;
            break;
        }
    }
    st[s] = true;
    path.emplace_back(s);
    dfs(s);
    path.pop_back();
    st[s] = false;
    bool has{};
    cout << ret.size() << "\n";
    for (auto x : ret) {
        if (has) cout << " ";
        else has = true;
        cout << x;
    }
    return 0;
}
