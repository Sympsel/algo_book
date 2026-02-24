#include <iostream>
#include <cstring>
using namespace std;
const int p = 1e9 + 7;
using ll = long long;

struct mat {
    ll m[3][3];

    mat(bool to_unit = false) {
        memset(m, 0, sizeof m);
        if (to_unit)
            for (int i{}; i < 3; ++i)
                m[i][i] = 1;
    }

    void clear() {
        memset(m, 0, sizeof m);
    }

    void build() {
        clear();
        m[0][0] = m[0][1] = m[1][2] = m[2][0] = 1;
    }

    mat operator*(const mat& B) const {
        mat C;
        for (int i{}; i < 3; ++i)
            for (int j{}; j < 3; ++j)
                for (int k{}; k < 3; ++k)
                    C.m[i][j] = (C.m[i][j] + m[i][k] * B.m[k][j]) % p;
        return C;
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
    int T; cin >> T;
    ll n;
    mat B;
    for (int i{}; i < 3; ++i) B.m[0][i] = 1;
    while (T--) {
        cin >> n;
        if (n <= 3) {
            cout << "1\n";
            continue;
        }
        A.build();
        mat R{qpow(n - 3)};
        A = B * R;
        cout << A.m[0][0] << "\n";
    }
    return 0;
}