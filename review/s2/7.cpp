#include <deque>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 507;
int n, m;
string a[N];
int sx, sy, tx, ty;
int dx[]{1, -1, 0, 0};
int dy[]{0, 0, 1, -1};
using pii = pair<int, int>;
int f[N][N];


void bfs() {
    if (sx == tx && sy == ty) {
        cout << 0 << "\n";
        return;
    }
    deque<pii> q;
    q.emplace_back(sx, sy);
    f[sx][sy] = 0;

    while (q.size()) {
        auto [x, y]{q.front()}; q.pop_front();
        if (x == tx && y == ty) {
            cout << f[x][y] << "\n";
            return;
        }

        for (int i{}; i < 4; ++i) {
            int r{x + dx[i]}, c{y + dy[i]};
            if (r < 0 || r >= n || c < 0 || c >= m) continue;
            int w{a[x][y] == a[r][c] ? 0 : 1};
            if (f[r][c] == -1) {
                if (w == 0) q.emplace_front(r, c);
                else q.emplace_back(r, c);
                f[r][c] = f[x][y] + w;
            } else if (f[x][y] + w < f[r][c]) {
                f[r][c] = f[x][y] + w;
            } else {}
        }
    }
}

int main() {
    while (cin >> n >> m, n && m) {
        for (int i{}; i < n; ++i) cin >> a[i];
        cin >> sx >> sy >> tx >> ty;
        memset(f, -1, sizeof f);
        bfs();
    }
    return 0;
}