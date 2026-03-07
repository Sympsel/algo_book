#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n; cin >> x >> n;
    int sum{}, _;
    for (int i{}; i < n; ++i) {
        cin >> _;
        sum += _;
    }
    int ret{sum - x * (n - 1)};
    cout << (ret >= 0 ? ret : 0);

    return 0;
}