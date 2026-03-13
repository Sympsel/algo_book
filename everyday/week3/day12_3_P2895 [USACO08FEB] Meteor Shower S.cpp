#include <bits/stdc++.h>
using namespace std;

const int N = 305;
int n{300}, m;
ll a[N][N];
bool st[N][N];
int dx[5]{1, -1, 0, 0, 0};
int dy[5]{0, 0, 1, -1, 0};
using ll = long long;

// -1 安全 2 不可到达 0 路径
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(a, -1, sizeof a);
    cin >> m;
    int x, y, t;
    while (m--) {
        cin >> x >> y >> t;

        for (int i{}; i < 5; ++i) {
            int r{x + dx[i]}, c{y + dy[i]};
            if (r >= 0 && c >= 0) {
                if (a[r][c] == -1 || a[r][c] > t) {
                    a[r][c] = t;
                }
            }
        }
    }

    if (a[0][0] == 0) {
        cout << "-1\n";
        return 0;
    }

    ll ret{};
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    st[0][0] = true;
    while (q.size()) {
        t = q.size();
        while (t--) {
            auto& [i, j]{q.front()}; q.pop();
            if (a[i][j] == -1) {
                cout << ret << "\n";
                return 0;
            }
            for (int k{}; k < 4; ++k) {
                int r{i + dx[k]}, c{j + dy[k]};
                if (r >= 0 && c >= 0 && !st[r][c]) {
                    if (a[r][c] == -1 || a[r][c] > ret + 1) {
                        q.emplace(r, c);
                        st[r][c] = true;
                    }
                }
            }
        }
        ++ret;
    }
    cout << "-1\n";
    return 0;
}
