#include <bits/stdc++.h>
using namespace std;

const int p = 1e9 + 7;
using ll = long long;
ll n;

struct mat {
    ll m[2][2];

    mat(bool to_unit = false) {
        memset(m, 0, sizeof m);
        if (to_unit)
            m[0][0] = m[1][1] = 1;
    }

    mat operator*(const mat& B) const {
        mat C;
        for (int i{}; i < 2; ++i)
            for (int j{}; j < 2; ++j)
                for (int k{}; k < 2; ++k)
                    C.m[i][j] = (C.m[i][j] + m[i][k] * B.m[k][j]) % p;
        return C;
    }
}A;

mat qpow(ll k) {
    mat R{true};
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

    cin >> n;
    if (n <= 2) {
        cout << "1\n";
        return 0;
    }
    A.m[0][0] = A.m[1][0] = A.m[0][1] = 1;
    mat C;
    C.m[0][0] = C.m[0][1] = 1;
    cout << (C * qpow(n - 2)).m[0][0] << "\n";

    return 0;
}