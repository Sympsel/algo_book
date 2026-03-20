#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int n, m;
pair<int, int> a[N], b[N];
int f[N][N];

inline int dist(int i, int j) {
    auto& [x1, y1]{a[i]};
    auto& [x2, y2]{b[j]};
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int x0, y0;
    cin >> x0 >> y0; a[0] = {x0, y0};
    cin >> x0 >> y0; b[0] = {x0, y0};
    string stra, strb;
    cin >> stra >> strb;
    for (int i{1}; i <= n; ++i) {
        char sign{stra[i - 1]};
        if (sign == 'E') a[i] = {a[i - 1].first + 1, a[i - 1].second};
        else if (sign == 'W') a[i] = {a[i - 1].first - 1, a[i - 1].second};
        else if (sign == 'N') a[i] = {a[i - 1].first, a[i - 1].second + 1};
        else if (sign == 'S') a[i] = {a[i - 1].first, a[i - 1].second - 1};
        else {}
    }

    for (int i{1}; i <= m; ++i) {
        char sign{strb[i - 1]};
        if (sign == 'E') b[i] = {b[i - 1].first + 1, b[i - 1].second};
        else if (sign == 'W') b[i] = {b[i - 1].first - 1, b[i - 1].second};
        else if (sign == 'N') b[i] = {b[i - 1].first, b[i - 1].second + 1};
        else if (sign == 'S') b[i] = {b[i - 1].first, b[i - 1].second - 1};
        else {}
    }

    for (int i{1}; i <= n; ++i) f[i][0] = dist(i, 0) + f[i - 1][0];
    for (int i{1}; i <= m; ++i) f[0][i] = dist(0, i) + f[0][i - 1];

    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= m; ++j) {
            f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + dist(i, j);
        }
    }
    cout << f[n][m] << "\n";
    return 0;
}
