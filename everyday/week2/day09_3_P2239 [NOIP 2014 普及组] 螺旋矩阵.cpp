#include <bits/stdc++.h>
using namespace std;

int n, x, y, cnt;
inline bool cmp(int _i, int _j) {
    if (_i == x && _j == y) {
        cout << cnt << "\n";
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> x >> y;
    int k{};
    bool flag = n % 2 == 0;
    if (flag) {
        k = min(min(x, n + 1 - x), min(y, n + 1 - y)) - 1;
    } else {
        int _{min(x, y)};
        if (_ <= n / 2 + 1) k = _ - 1;
        else k = n - _;
    }
    // cout << "k: " << k << "\n";
    for (int i{1}; i <= k; ++i) {
        cnt += (n - i * 2 + 1) * 4;
        // cout << cnt << "\n";
    }

    int _i = k + 1, _j = k + 1;
    ++cnt;
    if (_i == x && _j == y) {
        cout << cnt << "\n";
        return 0;
    }
    while (_j < n - k) {
        ++_j;
        ++cnt;
        if (cmp(_i, _j)) return 0;
    }
    while (_i < n - k) {
        ++_i;
        ++cnt;
        if (cmp(_i, _j)) return 0;
    }
    while (_j > k + 1) {
        --_j;
        ++cnt;
        if (cmp(_i, _j)) return 0;
    }
    while (_i > k + 1) {
        --_i;
        ++cnt;
        if (cmp(_i, _j)) return 0;
    }
    cout << cnt << "\n";

    return 0;
}
