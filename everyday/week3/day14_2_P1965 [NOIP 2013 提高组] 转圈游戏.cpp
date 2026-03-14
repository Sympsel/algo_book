#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll n, m, k, x;

ll qpow(ll a, ll b) {
    ll ret{1};
    while (b) {
        if (b & 1) ret = ret * a % n;
        b >>= 1;
        a = a * a % n;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k >> x;
    cout << (x + m * qpow(10, k) % n) % n << "\n";

    return 0;
}