#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    ll ret{};
    for (int i{1}; i <= n / i; ++i) {
        if (n % i == 0) {
            ret += i;
            if (i != n / i) ret += n / i;
        }
    }
    cout << ret << "\n";

    return 0;
}