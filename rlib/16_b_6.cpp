#include <iostream>
#include <string>
#include <queue>
using namespace std;

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};
using pii = pair<int, int>;
string vis[2];

int main() {
    string s[2];
    cin >> s[0] >> s[1];
    int n(s[0].size());
    vis[0] = string(n, '0');
    vis[1] = string(n, '0');

    pii b{};
    for (int i{}; i < 2; ++i) {
        for (int j{}; j < n; ++j) {
            if (s[i][j] == '#') {
                b.first = i, b.second = j;
                break;
            }
        }
    }
    queue<pii> q;
    q.emplace(b);
    vis[b.first][b.second] = '1';
    while (q.size()) {
        auto [x, y]{q.front()}; q.pop();
        for (int i{}; i < 4; ++i) {
            int r{x + dx[i]}, c{y + dy[i]};
            if (r < 0 && r >= 2 || c < 0 || c >= n || vis[r][c] == '1') continue;
            if (s[r][c] == '#') {
                q.emplace(r, c);
            }
            vis[r][c] = '1';
        }
    }

    while (q.size()) {
        int sz(q.size());
        while (sz--) {
            auto [x, y]{q.front()}; q.pop();
        }
    }

    return 0;
}