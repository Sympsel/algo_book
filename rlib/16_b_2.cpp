#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7;
using ll = long long;
ll qpow(ll b) {
    ll ret{1};
    ll a{2};
    while (b) {
        if (b & 1) ret = ret * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ret;
}

int main() {
    cout << qpow(1012);
    return 0;
}