#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;
const int INF = 0x3f3f3f3f;
int n;
struct edge {
    int u, v, w;
    edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
    bool operator<(const edge& o) const {
        return w > o.w;
    }
};
priority_queue<edge> ed;
int uf[N];
inline int fd(int x) {
    return x == uf[x] ? x : uf[x] = fd(uf[x]);
}

int kk() {
    int cnt{}, ret{};
    while (ed.size()) {
        auto [u, v, w]{ed.top()}; ed.pop();
        int fx{fd(u)}, fy{fd(v)};
        if (fx != fy) {
            uf[fx] = fy;
            ++cnt;
            ret += w;
        }
    }
    return cnt == n - 1 ? ret : INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    for (int i{1}; i <= n; ++i) uf[i] = i;
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        ed.emplace(u, v, w);
        ed.emplace(v, u, w);
    }
    int ret{kk()};
    if (ret == INF) cout << "orz\n";
    else cout << ret << "\n";
    return 0;
}
