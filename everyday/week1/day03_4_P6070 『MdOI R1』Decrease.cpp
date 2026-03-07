#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 6;
int n, k;
int a[N][N];
using ll = long long;

inline int _read() {
    int ret{}, flag{1};
    char ch{getchar()};
    while (ch < '0' || ch > '9') {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret * flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m; n = _read(); m = _read(); k = _read();
    int r, c, z;
    while (m--) {
        r = _read(); c = _read(); z = _read();
        a[r][c] += z;
        a[r + 1][c] -= z;
        a[r][c + 1] -= z;
        a[r + 1][c + 1] += z;
    }

    ll ret{};
    for (int i{1}; i <= n - k + 1; ++i) {
        for (int j{1}; j <= n - k + 1; ++j) {
            if (a[i][j]) {
                ret += abs(a[i][j]);
                a[i + k][j] += a[i][j];
                a[i][j + k] += a[i][j];
                a[i + k][j + k] -= a[i][j];
                a[i][j] = 0;
            }
        }
    }
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n; ++j) {
            if (a[i][j]) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    cout << ret << "\n";
    return 0;
}
