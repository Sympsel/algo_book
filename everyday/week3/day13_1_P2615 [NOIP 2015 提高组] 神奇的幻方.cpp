#include <bits/stdc++.h>
using namespace std;

const int N = 42;
int n;
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    f[1][(n + 1) / 2] = 1;
    int r{1}, c{(n + 1) / 2};
    for (int k{2}; k <= n * n; ++k) {
        if (c != n && r == 1) {
            f[n][c + 1] = k;
            r = n;
            ++c;
        } else if (c == n && r != 1) {
            f[r - 1][1] = k;
            --r;
            c = 1;
        } else if (r == 1 && c == n) {
            f[r + 1][c] = k;
            ++r;
        } else if (r != 1 && c != n) {
            if (f[r - 1][c + 1] == 0) {
                f[r - 1][c + 1] = k;
                --r; ++c;
            } else {
                f[r + 1][c] = k;
                ++r;
            }
        }
    }

    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n; ++j) {
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}