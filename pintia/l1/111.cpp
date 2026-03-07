#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll qpow(int a, int b) {
    ll ret{1};
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

    int x; cin >> x;

    int retI{};
    int retJ{};

    bool flag{true};
    for (int i{1}; flag; ++i) {
        ll sum{};
        flag = false;
        for (int j{1}; sum < x; ++j) {
            sum += qpow(j, i);
            if (sum > (ll)1e18) {
                flag = false;
                break;
            }
            flag = true;
            if (sum == x) {
                retI = i;
                retJ = j;
                break;
            }
        }
    }
    if (retI == 0) cout << "Impossible for " << x << ".";
    else {
        for (int i{1}; i <= retJ; ++i) {
            if (i > 1) cout << "+";
            cout << i << "^" << retI;
        }
    }

    return 0;
}