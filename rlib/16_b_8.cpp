#include <iostream>
using namespace std;

using ll = long long;
const int N = 1e5 + 7;
const int p = 1e9 + 7;
int n;
ll a[N];
ll _xor[N];

ll qpow(ll a, ll b) {
    int ret{1};
    while (b) {
        if (b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    for (int i{1}; i <= n; ++i)
        _xor[i] = _xor[i - 1] ^ a[i];

    ll ret{};
    for (int i{1}; i <= n - 1; ++i) {
        ret += _xor[i] * 2 * qpow(3, n - 1 - i) % p;
    }
    ret = (ret + _xor[n]) % p;
    cout << ret << "\n";
    return 0;
}