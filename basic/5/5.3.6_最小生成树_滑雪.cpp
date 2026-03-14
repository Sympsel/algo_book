#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 1e6 + 5;
using ll = long long;

int n, m;

struct edge {
    int u, v, w;
}ed[M];

int h[N];
vector<pair<int, int>> g[N];
int pos;
bool vis[N];
int cnt;
int uf[N];
ll ret;

void init() {
    cin >> n >> m;
    for (int i{1}; i <= n; ++i) {
        cin >> h[i];
        uf[i] = i;
    }

    int x, y, k;
    for (int i{1}; i <= m; ++i) {
        cin >> x >> y >> k;
        if (h[x] >= h[y]) g[x].emplace_back(y, k);
        if (h[x] <= h[y]) g[y].emplace_back(x, k);
    }
}


void bfs() {
    queue<int> q; q.emplace(1);
    vis[1] = true;
    ++cnt;

    while (q.size()) {
        int u{q.front()}; q.pop();

        for (auto& [v, w] : g[u]) {
            ed[++pos] = {u, v, w};

            if (vis[v]) continue;
            q.emplace(v);
            vis[v] = true;
            ++cnt;
        }
    }
}

int fd(int x) {
    return uf[x] == x ? x : uf[x] = fd(uf[x]);
}

void kk() {
    for (int i{1}; i <= n; ++i) uf[i] = i;
    sort(ed + 1, ed + pos + 1, [](const edge& a, const edge& b) {
        if (h[a.v] == h[b.v]) return a.w < b.w;
        return h[a.v] > h[b.v];
    });
    for (int i{1}; i <= pos; ++i) {
        auto[u, v, w]{ed[i]};
        int fx{fd(u)}, fy{fd(v)};
        if (fx == fy) continue;
        ret += w;
        uf[fx] = fy;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    bfs();
    kk();
    cout << cnt << " " << ret << "\n";
    return 0;
}
