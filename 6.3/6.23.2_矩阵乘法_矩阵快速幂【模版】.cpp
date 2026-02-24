#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 102;
const int p = 1e9 + 7;
ll n, k;

struct mat {
    ll m[N][N];

    mat(bool to_unit = false) {
        memset(m, 0, sizeof m);
        if (to_unit)
            for (int i{1}; i <= n; ++i)
                m[i][i] = 1;
    }

    mat operator*(const mat& B) const {
        mat C;
        for (int i{1}; i <= n; ++i)
            for (int j{1}; j <= n; ++j)
                for (int k{1}; k <= n; ++k)
                    C.m[i][j] = (C.m[i][j] + m[i][k] * B.m[k][j]) % p;
        return C;
    }

    void print() {
        for (int i{1}; i <= n; ++i) {
            for (int j{1}; j <= n; ++j)
                cout << m[i][j] << " ";
            cout << "\n";
        }
    }
}A;

mat qpow(ll k) {
    mat R(true);
    while (k) {
        if (k & 1) R = R * A;
        k >>= 1;
        A = A * A;
    }
    return R;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i{1}; i <= n; ++i)
        for (int j{1}; j <= n; ++j)
            cin >> A.m[i][j];
    mat R{qpow(k)};
    R.print();

    return 0;
}