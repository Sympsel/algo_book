#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int M = 2e5 + 5;
int n, m;

struct edge {
    int u, v, w;
    edge() {}
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}

    bool operator<(const edge& o) const {
        return w < o.w;
    }
};

edge ed[M];
int uf[N];

int fd(int x) {
    return uf[x] == x ? x : uf[x] = fd(uf[x]);
}

int ret;
int cnt{1};

void krusal() {
    sort(ed + 1, ed + m + 1);
    for (int i{1}; i <= m; ++i) {
        auto [u, v, w]{ed[i]};
        int fx{fd(u)}, fy{fd(v)};
        if (fx == fy) continue;
        uf[fx] = fy;
        ret += w;
        ++cnt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i{1}; i <= n; ++i) uf[i] = i;
    int u, v, w;
    for (int i{1}; i <= m; ++i) {
        cin >> u >> v >> w;
        ed[i] = edge(u, v, w);
    }
    krusal();
    if (cnt < n) cout << "orz\n";
    else cout << ret << "\n";

    return 0;
}
