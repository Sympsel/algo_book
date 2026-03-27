#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, m, k;
vector<pair<int, int>> ed;
int a[N];

bool check() {
    unordered_set<int> st;
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        st.emplace(a[i]);
    }
    if (st.size() != k) return false;

    // for (int i{1}; i <= n; ++i) {
    //     for (int j{}; j < m; ++j) {
    //         auto [u, v]{ed[j]};
    //         if (u == i || v == i) {
    //             if (a[u] == a[v]) return false;
    //         }
    //     }
    // }
    for (int i{}; i < m; ++i) {
        auto [u, v]{ed[i]};
        if (a[u] == a[v]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    int u, v;
    ed.resize(m);
    for (int i{}; i < m; ++i) {
        cin >> u >> v;
        ed[i] = {u, v};
    }
    int T; cin >> T;
    while (T--) {
        if (check()) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
