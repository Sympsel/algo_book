#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll qpow(ll b) {
    ll ret{1}, a{2};
    while (b) {
        if (b & 1) ret = ret * a;
        b >>= 1;
        a = a * a;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    cout << "2^" << n << " = " << qpow(n);

    return 0;
}
