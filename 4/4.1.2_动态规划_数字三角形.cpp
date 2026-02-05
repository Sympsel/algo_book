#include <iostream>
using namespace std;

const int N = 1e3 + 3;

int a[N][N];
int n;
int f[N];
int main() {
    cin >> n;
    for (int i{}; i < n; ++i)
        for (int j{}; j <= i; ++j)
            cin >> a[i][j];
    
    f[0] = a[0][0];
    for (int i{1}; i < n; ++i) {
        for (int j{i}; j > 0; --j)
        f[j] = max(f[j - 1], f[j]) + a[i][j];
        f[0] += a[i][0];
    }
    int ret{};
    for (int i{}; i < n; ++i)
        ret = max(ret, f[i]);
    cout << ret << "\n"; 
    return 0;
}
 

// int a[N][N];
// int f[N][N];
// int n;

// int main() {
//     cin >> n;
//     for (int i{}; i < n; ++i)
//         for (int j{}; j <= i; ++j)
//             cin >> a[i][j];
// 
//     for (int i{}; i < n; ++i) {
//         for (int j{}; j <= i; ++j) {
//             if (i > 0) {
//                 f[i][j] = f[i - 1][j];
//                 if (j > 0) f[i][j] = max(f[i - 1][j - 1], f[i][j]);
//             } 
//             f[i][j] += a[i][j];
//         }
//     }
//     int ret{};
//     for (int i{}; i < n; ++i)
//         ret = max(ret, f[n - 1][i]);
//     cout << ret << "\n";
//     return 0;
// }

