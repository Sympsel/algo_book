#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    cin >> x;
    ll s{};
    while (true) {
        ++s;
        vector<int> A(s);
        vector<int> C(s);
        fill(A.begin(), A.end(), 1);
        fill(C.begin(), C.end(), 0);
        ll t{};
        for (ll i{}; i < s; ++i) {
            t = 10 * t + A[i];
            C[i] = t / x;
            t %= x;
        }
        if (t == 0) {
            ll j{};
            while (C[j] == 0) ++j;
            while (j < s) {
                cout << C[j++];
            }
            cout << " " << s;
            return 0;
        }
    }

    return 0;
}
