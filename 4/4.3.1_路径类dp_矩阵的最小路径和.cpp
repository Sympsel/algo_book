#include <iostream>
#include <cstring>
using namespace std;

const int N = 505;
int a[N][N];
int f[N][N];
int n, m;
int main() {
    int m, n;
    cin >> n >> m;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    f[1][1] = a[1][1];
    for (int i{2}; i <= n; ++i) f[i][1] = f[i - 1][1] + a[i][1];
    for (int i{2}; i <= m; ++i) f[1][i] = f[1][i - 1] + a[1][i];
    for (int i{2}; i <= n; ++i) {
        for (int j{2}; j <= m; ++j) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
        }
    }
    cout << f[n][m] << "\n";
    return 0;
}
