#include <bits/stdc++.h>
using namespace std;

const int p = 100003;
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
    ll m, n;
    cin >> m >> n;
    ll ret{qpow(m, n) - m * qpow(m - 1, n - 1) % p};
    ret = (ret % p + p) % p;
    cout << ret << "\n";


    return 0;
}