#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{1}; i <= n; ++i)
        cin >> a[i];
    int ret{};
    for (int i{1}; i < n; ++i) {
        if (a[i - 1] > a[i] && a[i] < a[i + 1]) ++ret;
        else if (a[i - 1] < a[i] && a[i] > a[i + 1]) ++ret;
        else {}
    }
    cout << ret + 1 << "\n";
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 7;
// int a[N], f[N], g[N];
// int n;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n;
//     for (int i{1}; i <= n; ++i)
//         cin >> a[i];
//     f[1] = g[1] = 1;
//     for (int i{2}; i <= n; ++i) {
//         if (a[i] > a[i - 1]) {
//             f[i] = max(f[i - 1], g[i - 1] + 1);
//             g[i] = g[i - 1];
//         } else if (a[i] < a[i - 1]) {
//             f[i] = f[i - 1];
//             g[i] = max(g[i - 1], f[i - 1] + 1);
//         } else {
//             f[i] = f[i - 1];
//             g[i] = g[i - 1];
//         }
//     }
//     cout << max(f[n], g[n]) << "\n";
//     return 0;
// }
