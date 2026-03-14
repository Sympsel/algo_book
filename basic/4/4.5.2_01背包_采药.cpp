#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1010;
int n, m;
int f[M];
int t[N], v[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i{1}; i <= n; ++i) cin >> t[i] >> v[i];

    for (int i{1}; i <= n; ++i) {
        for (int j{m}; j >= t[i]; --j) {
            f[j] = max(f[j], f[j - t[i]] + v[i]);
        }
    }
    cout << f[m] << "\n";

    return 0;
}
