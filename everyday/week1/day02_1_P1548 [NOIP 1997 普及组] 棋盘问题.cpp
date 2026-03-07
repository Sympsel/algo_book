#include <bits/stdc++.h>
using namespace std;

const int N = 103;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    ll retA{}, retB{};
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= m; ++j) {
            if (i != j) {
                retB += (n - i + 1) * (m - j + 1);
            } else {
                retA += (n - i + 1) * (m - j + 1);
            }
        }
    }
    cout << retA << " " << retB << "\n";
    return 0;
}
