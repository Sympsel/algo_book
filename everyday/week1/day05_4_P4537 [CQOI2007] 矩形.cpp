#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 10;
bool st[N][N];
int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};

ll ret;
int n, m;

void dfs(int x, int y) {
    if (x < 1 || x >= n || y < 1 || y >= m) {
        ++ret;
        return;
    }
    st[x][y] = true;
    for (int i{}; i < 4; ++i) {
        int r{x + dx[i]}, c{y + dy[i]};
        if (!st[r][c]) {
            dfs(r, c);
        }
    }
    st[x][y] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i{1}; i < n; ++i) {
        st[i][0] = true;
        dfs(i, 1);
        st[i][0] = false;
    }
    for (int i{1}; i < m; ++i) {
        st[0][i] = true;
        dfs(1, i);
        st[0][i] = false;
    }
    cout << ret;

    return 0;
}
