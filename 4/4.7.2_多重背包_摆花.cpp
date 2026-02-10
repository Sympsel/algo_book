#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int p = 1e6 + 7;
int f[N];
int x[N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    f[0] = 1;
    for (int i{1}; i <= n; ++i) cin >> x[i];

    for (int i{1}; i <= n; ++i) {
        for (int j{m}; j >= 0; --j) {
            for (int k{1}; k <= min(x[i], j); ++k)
                f[j] = (f[j] + f[j - k]) % p;
        }
    }
    cout << f[m] << "\n";

    return 0;
}
