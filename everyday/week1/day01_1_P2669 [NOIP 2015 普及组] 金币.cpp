#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k; cin >> k;
    int n{};
    while (n * (n + 1) / 2 <= k)
        ++n;
    --n;
    ll ret = n * (n + 1) * (2 * n + 1) / 6 + (k - n * (n + 1) / 2) * (n + 1);
    cout << ret << "\n";

    return 0;
}
