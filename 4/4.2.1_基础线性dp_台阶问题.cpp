#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
const int p = 1e5 + 3;
int f[N];

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    f[0] = 1;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= k && i - j >= 0; ++j) {
            f[i] = (f[i] + f[i - j]) % p;
        }
    }
    cout << f[n] << "\n";

    return 0;
}

