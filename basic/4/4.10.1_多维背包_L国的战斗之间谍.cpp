#include <bits/stdc++.h>
using namespace std;

int n, m, x;
const int N = 105;
const int M = 1005;
const int X = 1005;
int v[N], a[N], b[N];
int f[M][X];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x;
    for (int i{1}; i <= n; ++i)
        cin >> v[i] >> a[i] >> b[i];

    for (int i{1}; i <= n; ++i) {
        for (int j{m}; j >= a[i]; --j) {
            for (int k{x}; k >= b[i]; --k) {
                f[j][k] = max(f[j][k], f[j - a[i]][k - b[i]] + v[i]);
            }
        }
    }
    cout << f[m][x] << "\n";

    return 0;
}
