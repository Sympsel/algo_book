#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 7;
using ll = long long;
int n;
ll a[N];
int mp[7];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    memset(mp, -1, sizeof mp);
    mp[0] = 0;
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
        int mod(a[i] % 7);
        if (mp[mod] == -1) {
            mp[mod] = i;
        }
    }
    // for (int i{1}; i <= n; ++i) {
    //     cout << a[i] << " \n"[i == n];
    // }
    // for (int i{}; i <= 6; ++i) {
    //     cout << mp[i] << " \n"[i == 6];
    // }

    int ret{};
    for (int i{1}; i <= n; ++i)
        // 由于mod只取出现过的值，因此不用下面这行if判断·
        // if (mp[a[i] % 7] != -1)
        ret = max(ret, i - mp[a[i] % 7]);
    cout << ret << "\n";

    return 0;
}