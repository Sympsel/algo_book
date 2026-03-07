#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    if (n == 1) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> a;
    while (n) {
        int t{1};
        while (t * 2 <= n) {
            t *= 2;
        }
        a.emplace_back(t);
        n -= t;
        if (n == 1) {
            cout << -1 << "\n";
            return 0;
        }
    }
    for (auto x : a) {
        cout << x << " ";
    }

    return 0;
}
