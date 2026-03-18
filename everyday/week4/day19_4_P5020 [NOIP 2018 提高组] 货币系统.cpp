#include <bits/stdc++.h>
using namespace std;

const int N = 103;
const int M = 25010;
int n, m{25000};
bool f[M];
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >>T;
    while (T--) {
        cin >> n;
        for (int i{1}; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        memset(f, 0, sizeof f);
        f[0] = true;
        int cnt{};
        for (int i{1}; i <= n; ++i) {
            if (!f[a[i]]) ++cnt;
            for (int j{a[i]}; j <= m; ++j) {
                f[j] = f[j] || f[j - a[i]];
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}