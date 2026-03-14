#include <bits/stdc++.h>
using namespace std;

const int N{403};
const int p(1e9 + 7);
using ll = long long;
int n;
ll a[N][N * 2];

ll qpow(ll a, ll k) {
    ll ret{1};
    while (k) {
        if (k & 1) ret = ret * a % p;
        k >>= 1;
        a = a * a % p;
    }
    return ret;
}

bool gauss() {
    for (int i{1}; i <= n; ++i) {
        int aim{i};
        for (int j{1}; j <= n; ++j) {
            if (j < i && a[j][j] != 0) continue;
            if (a[j][i] > a[aim][i]) aim = j;
        }
        if (a[aim][i] == 0) return false;

        for (int j{1}; j <= 2 * n; ++j) swap(a[i][j], a[aim][j]);

        ll tmp{qpow(a[i][i], p - 2)};
        for (int j{i}; j <= 2 * n; ++j) a[i][j] = a[i][j] * tmp % p;
        for (int j{1}; j <= n; ++j) {
            if (j == i) continue;
            ll t{a[j][i]};
            for (int k{i}; k <= 2 * n; ++k) {
                a[j][k] -= t * a[i][k];
                a[j][k] = (a[j][k] % p + p) % p;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{1}; i <= n; ++i) {
        a[i][i + n] = 1;
        for (int j{1}; j <= n; ++j)
            cin >> a[i][j];
    }

    bool ret{gauss()};
    if (ret) {
        for (int i{1}; i <= n; ++i) {
            for (int j{1}; j <= n; ++j)
                cout << a[i][j + n] << " ";
            cout << "\n";
        }
    } else cout << "No Solution\n";

    return 0;
}
