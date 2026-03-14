#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
// 全局变量默认初始化为0
int n, a[N], f[N];

int e{};
void fd(int v) {
    if (f[e] < v) {
        f[++e] = v;
    } else if (f[e] > v) {
        int l{1}, r{e};
        while (l < r) {
            int mid{(l + r) / 2};
            if (f[mid] < v) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        f[l] = v;
    } else {}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];

    f[++e] = a[1];
    for (int i{2}; i <= n; ++i) {
        fd(a[i]);
    }
    cout << e << "\n";

    return 0;
}
