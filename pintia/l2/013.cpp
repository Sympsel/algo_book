#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n;
using ll = long long;
int a[N];
ll f[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];

    ll ret{};
    for (int i{1}; i <= n; ++i) {
        f[i] = 1;
        for (int j{1}; j < i; ++j) {
            if (a[i] > a[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ret = max(ret, f[i]);
    }
    cout << ret << "\n";

    return 0;
}
