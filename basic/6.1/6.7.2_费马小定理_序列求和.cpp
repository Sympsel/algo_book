#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int p = 1e9 + 7;

ll n;

ll qpow(ll a, ll b) {
    ll ret{1};
    while (b) {
        if (b & 1) ret = ret * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        ll ret{(n % p * qpow(6, p - 2)) % p};
        ret = ((n + 1) % p * ret) % p;
        ret = ((2 * n + 1) % p * ret) % p;
        cout << ret << "\n";
    }

    return 0;
}