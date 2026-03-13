#include <bits/stdc++.h>
using namespace std;

const int M = 1e4 + 7;
int n, m;
int f[M];
int a[M], b[M], t[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int ret{};
    for (int i{1}; i <= m; ++i) {
        cin >> t[i] >> a[i] >> b[i];
        f[i] = 1;
        for (int j{1}; j < i; ++j) {
            if (t[i] - t[j] >= abs(a[i] - a[j]) + abs(b[i] - b[j])) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ret = max(f[i], ret);
    }
    cout << ret << "\n";

    return 0;
}
