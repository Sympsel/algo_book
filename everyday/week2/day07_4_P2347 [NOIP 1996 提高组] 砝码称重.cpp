#include <bits/stdc++.h>
using namespace std;

int w[7]{0,1,2,3,5,10,20};
const int N = 1003;
int cnt[N];
int f[N];
int n = 6, m = 1000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i{1}; i <= n; ++i) {
        cin >> cnt[i];
    }

    f[0] = true;
    for (int i{1}; i <= n; ++i) {
        for (int j{m}; j >= 0; --j) {
            for (int k{}; k <= cnt[i] && j >= k * w[i]; ++k) {
                f[j] = f[j] || f[j - k * w[i]];
            }
        }
    }
    int ret{};
    for (int i{1}; i <= m; ++i)
        if (f[i]) ++ret;
    cout << "Total=" << ret;
    return 0;
}
