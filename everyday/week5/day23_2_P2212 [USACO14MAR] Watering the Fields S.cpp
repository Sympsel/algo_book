#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 7;
int n;
int m;
pair<int, int> a[N];
struct edge {
    int u, v, w;
    edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
    bool operator<(const edge& o) const {
        return w > o.w;
    }
};
using ll = long long;

int uf[N];

int fd(int x) {
    return x == uf[x] ? x : uf[x] = fd(uf[x]);
}

void un(int x, int y) {
    uf[fd(x)] = uf[fd(y)];
}

priority_queue<edge> q;

ll ret{};
int cnt{};
void kk() {
    while (q.size()) {
        auto [u, v, w]{q.top()}; q.pop();
        if (fd(u) != fd(v)) {
            ++cnt;
            un(u, v);
            ret += w;
            if (cnt == n - 1) {
                cout << ret << "\n";
                return;
            }
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int x, y;
    for (int i{1}; i <= n; ++i) {
        cin >> x >> y;
        a[i] = {x,y};
        uf[i] = i;
    }

    int dist;
    for (int i{1}; i <= n; ++i) {
        for (int j{i + 1}; j <= n; ++j) {
            auto& [x1, y1]{a[i]};
            auto& [x2, y2]{a[j]};
            dist = (x1 - x2) * (x1 - x2) + (y2 - y1) * (y2 - y1);
            if (dist >= m) {
                q.emplace(i, j, dist);
            }
        }
    }
    kk();
    return 0;
}