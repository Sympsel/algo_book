#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 5e4 + 5;
int f[N];

int fd(int x) {
    int l{1}, r{n};
    while (l < r) {
        int mid{(l + r) / 2};
        if (x >= f[mid]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> n >> q;
    for (int i{1}; i <= n; ++i) {
        cin >> f[i];
        f[i] += f[i - 1];
    }

    int x;
    while (q--) {
        cin >> x;
        cout << fd(x) << "\n";
    }

    return 0;
}
