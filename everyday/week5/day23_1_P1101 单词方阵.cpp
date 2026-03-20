#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const string str{"yizhong"};
int n;
char a[N][N];
int dx[8]{1, -1, 1, -1, 1, -1, 0, 0};
int dy[8]{1, -1, -1, 1, 0, 0, 1, -1};

int ret{};
vector<pair<pair<int, int>, int>> path;

void dfs(int x, int y) {
    for (int i{}; i < 8; ++i) {
        int r{x}, c{y};
        for (int j{1}; j <= 6; ++j) {
            r += dx[i], c += dy[i];
            if (r < 1 || r > n || c < 1 || c > n) goto next;
            if (a[r][c] != str[j]) goto next;
        }
        path.emplace_back(make_pair(x, y), i);
        next:;
    }
}

void output() {
    memset(a, '*', sizeof a);
    for (auto& [pos, dir] : path) {
        auto [x, y]{pos};
        a[x][y] = 'y';
        for (int i{1}; i <= 6; ++i) {
            x += dx[dir], y += dy[dir];
            a[x][y] = str[i];
        }
    }
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n; ++j) {
            cout << a[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    string _;
    for(int i{1}; i <= n; ++i) {
        cin >> _;
        for (int j{1}; j <= n; ++j) {
            a[i][j] = _[j - 1];
        }
    }

    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n; ++j) {
            if (a[i][j] == 'y') {
                dfs(i, j);
            }
        }
    }
    output();

    return 0;
}
