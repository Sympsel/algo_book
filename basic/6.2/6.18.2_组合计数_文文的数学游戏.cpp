#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
using ll = long long;
const int p = 1e9 + 7;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    int m{0x3f3f3f3f};
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        m = min(m, a[i]);
    }

    ll ret{1};
    for (int i{1}; i <= n; ++i) {
        ret = ret * (a[i] / m) % p;
    }
    cout << m << " " << ret << "\n";

    return 0;
}