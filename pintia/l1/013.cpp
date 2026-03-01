#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 13;
int f[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    f[0] = 1;
    ll ret{};
    for (int i{1}; i <= n; ++i) {
        f[i] = i * f[i - 1];
        ret += f[i];
    }
    cout << ret;


    return 0;
}
