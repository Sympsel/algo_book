#include <bits/stdc++.h>
using namespace std;

const int p = 998244353;
using ll = long long;

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

    int n, k; cin >> n >> k;
    ll ret{qpow(qpow(2, k) - 1, n)};
    cout << ret << "\n";

    return 0;
}