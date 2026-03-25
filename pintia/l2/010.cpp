#include <bits/stdc++.h>
using namespace std;

const int N = 103;
int n, m, t;
int uf[N]; // 朋友
unordered_set<int> err[N];
int fd(int x) {
    return x == uf[x] ? x : uf[x] = fd(uf[x]);
}

void un(int x, int y) {
    uf[fd(x)] = fd(y);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> t;
    for (int i{1}; i <= n; ++i) uf[i] = i;
    int u, v, st;
    while (m--) {
        cin >> u >> v >> st;
        if (st == 1) {
            un(u, v);
        } else if (st == -1) {
            err[u].emplace(v);
            err[v].emplace(u);
        } else {}
    }
    while (t--) {
        cin >> u >> v;
        int fx{fd(u)}, fy{fd(v)};
        bool is_err{err[u].count(v) || err[v].count(u)};
        if (fx != fy && !is_err) {
            cout << "OK\n";
        } else if (fx == fy && !is_err) {
            cout << "No problem\n";
        } else if (fx != fy && is_err) {
            cout << "No way\n";
        } else {
            cout << "OK but...\n";
        }
    }
    return 0;
}
