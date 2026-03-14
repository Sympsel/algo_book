#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1e4 + 5;
int f[M];
int a[N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    memset(f, 0, sizeof f);
    f[0] = 1;
    for (int i{1}; i <= n; ++i)
        for (int j{m}; j >= a[i]; --j)
            f[j] = f[j] + f[j - a[i]];

    cout << max(f[m], 0) << "\n";

    return 0;
}