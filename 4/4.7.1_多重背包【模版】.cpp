#include <bits/stdc++.h>
using namespace std;

const int N = 110 * 5;
int n, m;
int f[N];
int w[N], v[N];
int pos;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // 打包
    for (int i{1}; i <= n; ++i) {
        int x, y, z; cin >> x >> y >> z;
        int t{1};
        while (x >= t) {
            ++pos;
            w[pos] = t * y;
            v[pos] = t * z;
            x -= t;
            t <<= 1;
        }
        if (x) {
            ++pos;
            w[pos] = x * y;
            v[pos] = x * z;
        }
    }

    for (int i{1}; i <= pos; ++i) {
        for (int j{m}; j >= w[i]; --j) {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[m] << "\n";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 105;
// int n, m;
// int f[N];
// // weight value
// int x[N], w[N], v[N];

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> m;
//     for (int i{1}; i <= n; ++i) cin >> x[i] >> w[i] >> v[i];

//     for (int i{1}; i <= n; ++i)
//         for (int j{m}; j >= 0; --j)
//             for (int k{}; k <= x[i] && j >= k * w[i]; ++k)
//                 f[j] = max(f[j], f[j - k * w[i]] + k * v[i]);
//     cout << f[m] << "\n";

//     return 0;
// }