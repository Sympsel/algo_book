#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 4;
struct node {
    int x, y, z;
    node(int _x = 0, int _y = 0, int _z = 0) : x(_x), y(_y), z(_z) {}

    bool operator<(const node& o) const {
        if (x != o.x) return x < o.x;
        if (y != o.y) return y < o.y;
        return z < o.z;
    }
}a[N];
map<node, bool> vis;


int n, h, r;

double dist(const node& u, const node& v) {
    auto [x1, y1, z1]{u};
    auto [x2, y2, z2]{v};
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

bool cross(const node& u, const node& v) {
    double d{dist(u, v)};
    return 2 * r >= d;
}

void bfs() {
    queue<node> q;
    for (int i{1}; i <= n; ++i) {
        auto& [_1, _2, z]{a[i]};
        if (z <= r) {
            q.emplace(a[i]);
            vis[a[i]] = true;
        }
    }

    while (q.size()) {
        node u{q.front()};
        q.pop();
        if (u.z >= h) {
            cout << "Yes\n";
            return;
        }

        for (int i{1}; i <= n; ++i) {
            node v{a[i]};
            if (!vis[v] && cross(u, v)) {
                q.emplace(v);
                vis[v] = true;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        pos = 0; cin >> n >> h >> r;
        // 减去后，当高度大于h时可以直接输出Yes
        h -= r;
        int _x, _y, _z;
        for (int i{1}; i <= n; ++i) {
            cin >> _x >> _y >> _z;
            a[i] = {_x, _y, _z};
        }
        if (h <= 0) {
            cout << "Yes\n";
            continue;
        }

        vis.clear();
        bfs();
    }

    return 0;
}
