#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 3e6 + 7;
ll inv[N], n, p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p;
    inv[1] = 1;
    cout << "1\n";
    for (int i{2}; i <= n; ++i) {
        inv[i] = p - (p / i) * inv[p % i] % p;
        cout << inv[i] << "\n";
    }

    return 0;
}