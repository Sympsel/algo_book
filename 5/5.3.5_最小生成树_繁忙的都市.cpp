#include <bits/stdc++.h>
using namespace std;

const int N = 305;
const int M = 8e3 + 5;
int n, m;
struct edge {
    int u, v, w;
    bool operator<(const edge& o) const {
        return w < o.w;
    }
} ed[M];
int uf[N];

int fd(int x) {
    return uf[x] == x ? x : uf[x] = fd(uf[x]);
}

int kk() {
    sort(ed + 1, ed + m + 1);
    int ret{};
    for (int i{1}; i <= m; ++i) {
        auto [u, v, w]{ed[i]};
        int fx{fd(u)}, fy{fd(v)};
        if (fx == fy) continue;
        uf[fx] = fy;
        ret = max(ret, w);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i{1}; i <= n; ++i) uf[i] = i;
    for (int i{1}; i <= m; ++i)
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
    int ret{kk()};

    cout << n - 1 << " " << ret << "\n";
    return 0;
}