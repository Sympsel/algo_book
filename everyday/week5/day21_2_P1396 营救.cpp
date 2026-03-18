#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
const int N = 1e4 + 7;
const int M = 2e4 + 7;
struct edge {
    int u, v, w;
    edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
    bool operator<(const edge& o) const {
        return w < o.w;
    }
}ed[M];

int uf[N];
int fd(int x) {
    return x == uf[x] ? x : uf[x] = fd(uf[x]);
}

void un(int x, int y) {
    uf[fd(x)] = fd(y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> s >> t;
    for (int i{1}; i <= n; ++i) uf[i] = i;
    int u, v, w;
    for (int i{1}; i <= m; ++i) {
        cin >> u >> v >> w;
        ed[i] = {u, v, w};
    }
    int ret{ed[s].w};
    sort(ed + 1, ed + 1 + m);
    for (int i{1}; i <= m; ++i) {
        auto& [u, v, w]{ed[i]};
        int fx{fd(u)}, fy{fd(v)};
        if (fx == fy) continue;
        ret = w;
        un(fx, fy);
        if (fd(s) == fd(t)) {
            break;
        }
    }

    cout << ret << "\n";
    return 0;
}
