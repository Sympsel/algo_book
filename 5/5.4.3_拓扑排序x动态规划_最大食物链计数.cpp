#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
const int M = 5e5 + 5;

int n, m;
int in[N], out[N];
vector<int> g[N];
int f[N];
const int p = 80112002;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m; int u, v;
    for (int i{1}; i <= m; ++i) {
        cin >> u >> v;
        g[u].emplace_back(v);
        ++in[v]; ++out[u];
    }

    queue<int> q;
    for (int i{1}; i <= n; ++i) {
        if (in[i] == 0) {
            f[i] = 1;
            q.emplace(i);
        }
    }

    while (q.size()) {
        auto t{q.front()}; q.pop();

        for (auto _ : g[t]) {
            f[_] = (f[_] + f[t]) % p;
            --in[_];
            if (in[_] == 0) q.emplace(_);
        }
    }
    int ret{};
    for (int i{1}; i <= n; ++i)
        if (out[i] == 0)
            ret = (ret + f[i]) % p;
    cout << ret <<"\n";
    return 0;
}
