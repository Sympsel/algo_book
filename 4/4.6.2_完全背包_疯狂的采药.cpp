#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 3;
const int M = 1e7 + 3;
long long f[M];
int t[N], v[N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    for (int i{1}; i <= n; ++i) cin >> t[i] >> v[i];

    for (int i{1}; i <= n; ++i)
        for (int j{t[i]}; j <= m; ++j)
            f[j] = max(f[j], f[j - t[i]] + v[i]);

    cout << f[m] << "\n";

    return 0;
}