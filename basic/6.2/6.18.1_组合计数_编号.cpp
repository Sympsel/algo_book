#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int p = 1e9 + 7;
const int N = 53;
int a[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll ret{1};
    int n; cin >> n;
    int _;
    for (int i{}; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    for (int i{}; i < n; ++i) {
        if (a[i] - i < 0) {
            cout << "0\n";
            return 0;
        }
        ret = ret * (a[i] - i) % p;
    }
    cout << ret << "\n";
    return 0;
}