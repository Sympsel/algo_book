#include <iostream>
using namespace std;

int n, m, t;
const int N = 10;
int a[N][N];
int st[N][N];
int f[N][N];
int ret{};
int x1, _y1, x2, y2;
int dx[4]{1, -1, 0,0};
int dy[4]{0,0,1,-1};

void dfs(int x, int y) {
    if (x == x2 && y == y2) {
        ++ret;
        return;
    }
    st[x][y] = 1;

    for (int k{}; k < 4; ++k) {
        int r{x + dx[k]}, c{y + dy[k]};
        if (r > n || r < 1 || y > m || y < 1) continue;
        if (st[r][c] == 0) {
            dfs(r, c);
        }
    }
    st[x][y] = 0;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> t;
    cin >> x1 >> _y1 >> x2 >> y2;
    int x, y;
    while (t--) {
        cin >>x >> y;
        st[x][y] = -1;
    }
    dfs(x1, _y1);
    cout << ret << '\n';

    return 0;
}
