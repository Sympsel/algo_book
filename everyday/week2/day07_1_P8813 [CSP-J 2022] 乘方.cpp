#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll x = 1e9;
// ll qpow(ll a, ll b) {
//     ll ret{1};
//     while (b) {
//         if (b & 1) {
//             if (a > x / ret) return -1;
//             ret = ret * a;
//         }
//         if (ret > x)
//             return -1;
//         b >>= 1;
//         // a = a * a;
//         if (b > 0 && a > x / a) return -1;
//         if (b > 0) a = a * a;
//     }

//     return ret > x ? -1 : ret;
// }

ll qpow(ll a, ll b) {
    if (a > x) return -1;
    if (a == 1) return 1;
    ll ret{1};
    while (b) {
        if (b & 1) ret = ret * a;
        if (ret <= 0 || ret > x) return -1;
        b >>= 1;
        a = a * a;
        if (a <= 0) return -1;
    }

    return ret > x ? -1 : ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b; cin >> a >> b;
    ll ret{qpow(a, b)};
    cout << ret;

    return 0;
}
