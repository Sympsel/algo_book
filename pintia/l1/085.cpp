#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[6];
    for (int i{}; i < 6; ++i) cin >> a[i];
    int t; cin >> t;
    for (int i{}; i < 6; ++i) {
        if (i > 0) cout << " ";
        int x{7};
        for (int j{}; j < t;) {
            --x;
            if (x != a[i]) {
                ++j;
            }
        }
        cout << x;
    }

    return 0;
}