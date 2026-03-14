#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
const int M = 1e3 + 5;
int n, m;
int a[N];
int f1[M], f2[M];
const int p = 1e8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    f1[0] = 1;
    int* arr = f1, *brr = f2;
    for (int i{1}; i <= n; ++i) {
        for (int j{}; j < m; ++j)
            brr[j] = (arr[j] + arr[((j - a[i]) % m + m) % m]) % p;
        int* tmp{arr};
        arr = brr;
        brr = tmp;
    }

    cout << arr[0] - 1 << "\n";
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 2e3 + 5;
// const int M = 1e3 + 5;
// int n, m;
// int a[N];
// int f[N][M];
// const int p = 1e8;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> m;
//     for (int i{1}; i <= n; ++i) cin >> a[i];
//     f[0][0] = 1;
//     for (int i{1}; i <= n; ++i)
//         for (int j{}; j < m; ++j)
//             f[i][j] = (f[i - 1][j] + f[i - 1][((j - a[i]) % m + m) % m]) % p;

//     cout << f[n][0] - 1 << "\n";

//     return 0;
// }