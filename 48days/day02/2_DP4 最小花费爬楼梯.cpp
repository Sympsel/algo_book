#include <bits/stdc++.h>
using namespace std;

const int N = 1e5  + 7;
int n;
int a[N], f[N];
int main() {
    cin >> n;
    for (int i{1}; i <= n; ++i) cin >>a[i];
    if (n == 1) {
        cout << a[1];
        return 0;
    }
    f[1] = a[1];
    f[2] = a[2];
    for (int i{3}; i <= n + 1; ++i) {
        f[i] = min(f[i - 1], f[i - 2]) + a[i];
    }
    cout << f[n + 1];

    return 0;
}
