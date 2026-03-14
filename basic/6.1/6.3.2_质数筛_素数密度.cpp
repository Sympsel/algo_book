#include <bits/stdc++.h>
using namespace std;

int l, r;
const int N = 1e6;
int st1[N], st2[N];
int p[N], cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> l >> r;
    int n(sqrt(r));

    for (int i{2}; i <= n; ++i) {
        if (!st1[i]) p[++cnt] = i;
        for (int j{1}; 1ll * i * p[j] <= n; ++j) {
            st1[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }

    l = l == 1 ? 2 : l;
    for (int i{1}; i <= cnt; ++i) {
        int b{(l + p[i] - 1) / p[i]};
        b = max(p[i], b);
        for (int j{b}; 1ll * j * p[i] <= r; ++j) {
            st2[j * p[i] - l] = true;
        }
    }

    int ret{};
    for (int i{l}; i <= r; ++i)
        if (!st2[i - l]) ++ret;
    cout << ret << "\n";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 65536 + 4;
// const int M = 1e6 + 7;
// int l, r;
// vector<int> p;
// bool st1[N];
// bool st2[M];
// using ll = long long;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> l >> r;
//     l = l == 1 ? 2 : l;
//     int n(sqrt(r));
//     for (ll i{2}; i <= n; ++i) {
//         if (!st1[i]) p.emplace_back(i);
//         if (1LL * i * i <= n) {
//             for (auto& x : p) {
//                 st1[i * x] = true;
//                 if (i % x == 0) break;
//             }
//         }
//     }

//     for (auto& x : p) {
//         ll b{(l + x - 1) / x * x};
//         b = max(1LL * x * x, b);
//         for (ll i{b}; i <= r; i += x)
//             st2[i - l] = true;
//     }

//     int ret{};
//     for (int i{l}; i <= r; ++i)
//         if (!st2[i - l]) ++ret;
//     cout << ret << "\n";

//     return 0;
// }

