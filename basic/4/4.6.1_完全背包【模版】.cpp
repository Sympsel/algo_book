#include <bits/stdc++.h>
using namespace std;

const int INF = -0x3f;
const int N = 1005;

int f[N];
int v[N], w[N];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i{1}; i <= n; ++i) cin >> v[i] >> w[i];
    for (int i{1}; i <= n; ++i)
        for (int j{v[i]}; j <= m; ++j)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m] << "\n";

    memset(f, INF, sizeof f);
    f[0] = 0;

    for (int i{1}; i <= n; ++i)
        for (int j{v[i]}; j <= m; ++j)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << max(f[m], 0) << "\n";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int INF = -0x3f;
// const int N = 1005;

// int f[N][N];
// int v[N], w[N];
// int n, m;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n >> m;
//     for (int i{1}; i <= n; ++i) cin >> v[i] >> w[i];
//     for (int i{1}; i <= n; ++i) {
//         for (int j{}; j <= m; ++j) {
//             f[i][j] = f[i - 1][j];
//             if (j >= v[i])
//                 f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
//         }
//     }
//     cout << f[n][m] << "\n";

//     memset(f, INF, sizeof f);
//     f[0][0] = 0;
//     for (int i{1}; i <= n; ++i) {
//         for (int j{}; j <= m; ++j) {
//             f[i][j] = f[i - 1][j];
//             if (j >= v[i])
//                 f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
//         }
//     }
//     cout << max(f[n][m], 0) << "\n";

//     return 0;
// }
