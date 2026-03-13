#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
using ll = long long;

int n;
int a[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ll ret{};
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        ret += max(a[i] - a[i - 1], 0);
    }
    cout << ret << "\n";

    return 0;
}
