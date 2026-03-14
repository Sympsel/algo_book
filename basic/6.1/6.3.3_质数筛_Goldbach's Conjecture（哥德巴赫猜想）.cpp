#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int n;
vector<int> p;
bool st[N];
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1e6;
    for (ll i{2}; i <= n; ++i) {
        if (!st[i]) p.emplace_back(i);

        for (auto x : p) {
            if (1LL * i * x > n) break;
            st[i * x] = true;
            if (i % x == 0) break;
        }
    }

    // int i{};
    // for (auto x : p) {
    //     cout << x << " ";

    //     if (++i % 20 == 0)
    //         cout << "\n";
    // }
    // cout << "\n";

    while (cin >> n, n) {
        for (auto& x : p) {
            if (x >= n / 2) break;
            if (!st[n - x]) {
                cout << n << " = " << x << " + " << (n - x) << "\n";
                break;
            }
        }
    }

    return 0;
}