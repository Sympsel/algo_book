#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i{1}; i <= n; ++i) cin >> a[i];
    int t, _; cin >> t;
    while (t--) {
        bool f1{true}, f2{};

        for (int i{1}; i <= n; ++i) {
            cin >> _;
            if (_) {
                if (_ == a[i]) f2 = true;
                else {
                    f1 = false;
                }
            }
        }
        if (f1 && f2) cout << "Da Jiang!!!\n";
        else cout << "Ai Ya\n";
    }

    return 0;
}
