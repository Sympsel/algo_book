#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n, k;
const int p = 1e9 + 7;

ll qpow(ll a, ll b) {
    int ret{1};
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

    int T; cin >> T;
    while (T--) {
        cin >> n >> k;
        ll ret{(qpow(k + 1, n + 1) - k - 1) * qpow(k, p - 2) % p};
        cout << (ret % p + p) % p << "\n";
    }

    return 0;
}