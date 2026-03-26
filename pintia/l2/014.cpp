// 二分 + 贪心
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n;
using ll = long long;
int a[N];
int f[N], len;

int main() {
    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    for (int i{1}; i <= n; ++i) {
        if (len == 0 || a[i] > f[len])
            f[++len] = a[i];
        else {
            int l{1}, r{len};
            while (l < r) {
                int mid{(l + r) / 2};
                if (f[mid] >= a[i]) r = mid;
                else l = mid + 1;
            }
            f[l] = a[i];
        }
    }
    cout << len << "\n";
    return 0;
}


// DP
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 7;
// int n;
// using ll = long long;
// int a[N];
// ll f[N];

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n;
//     for (int i{1}; i <= n; ++i) cin >> a[i];

//     ll ret{};
//     for (int i{1}; i <= n; ++i) {
//         f[i] = 1;
//         for (int j{1}; j < i; ++j) {
//             if (a[i] > a[j]) {
//                 f[i] = max(f[i], f[j] + 1);
//             }
//         }
//        ret = max(ret, f[i]);
//     }
//     cout << ret << "\n";

//     return 0;
// }
