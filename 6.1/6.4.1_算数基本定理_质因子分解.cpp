#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{2}; i <= n; ++i) {
        int x{i};
        for (int j{2}; j <= x / j; ++j) {
            int c{};
            while (x % j == 0) {
                x /= j;
                ++c;
            }
            if (c) mp[j] += c;
        }
        if (x > 1) ++mp[x];
    }

    for (auto& [k, v] : mp)
        cout << k << " " << v << "\n";
    return 0;
}