#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll get_phi(int x) {
    ll ret{x};
    for (int i{2}; i <= x / i; ++i) {
        if (x % i == 0) {
            ret = ret / i * (i - 1);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) ret = ret / x * (x - 1);
    return ret;
}

ll get_b(string& s, ll phi_p) {
    ll ret{};
    bool flag{};
    for (auto& ch : s) {
        ret = ret * 10 + ch - '0';
        if (ret >= phi_p) {
            flag = true;
            ret %= phi_p;
        }
    }
    if (flag) ret += phi_p;
    return ret;
}

ll qpow(ll a, ll b, ll p) {
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

    ll a, p;
    string s;

    cin >> a >> p >> s;
    ll phi_p{get_phi(p)};
    ll b{get_b(s, phi_p)};

    cout << qpow(a, b, p) << "\n";
    return 0;
}