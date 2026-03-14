#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int M = 1005;
int w[N], v[N], c[N];
int f1[M];
int f2[M];
int* arr = f1, *brr = f2;

int getM(const string& t1, const string& t2) {
    int i1(t1.find(':'));
    int i2(t2.find(':'));
    return 60 * (stoi(t2.substr(0, i2)) - stoi(t1.substr(0, i1)))
    + stoi(t2.substr(i2 + 1, t2.size())) - stoi(t1.substr(i1 + 1, t1.size()));
}
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string t1, t2;
    cin >> t1 >> t2 >> n;
    m = getM(t1, t2);

    for (int i{1}; i <= n; ++i) cin >> w[i] >> v[i] >> c[i];

    for (int i{1}; i <= n; ++i) {
        for (int j{}; j <= m; ++j) {
            brr[j] = arr[j];
            if (c[i]) {
                for (int k{1}; k <= c[i]; ++k)
                    if (j >= k * w[i])
                        brr[j] = max(arr[j], arr[j - k * w[i]] + k * v[i]);
            } else {
                if (j >= w[i])
                    brr[j] = max(arr[j], brr[j - w[i]] + v[i]);
            }
        }
        int* tmp{arr}
        arr = brr, brr = tmp;
    }
    cout << arr[m] << "\n";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e4 + 5;
// const int M = 1005;
// int w[N], v[N], c[N];
// int f[N][M];
// int n, m;

// int getM(const string& t1, const string& t2) {
//     int i1(t1.find(':'));
//     int i2(t2.find(':'));
//     return 60 * (stoi(t2.substr(0, i2)) - stoi(t1.substr(0, i1)))
//     + stoi(t2.substr(i2 + 1, t2.size())) - stoi(t1.substr(i1 + 1, t1.size()));
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     string t1, t2;
//     cin >> t1 >> t2 >> n;
//     m = getM(t1, t2);

//     for (int i{1}; i <= n; ++i) cin >> w[i] >> v[i] >> c[i];

//     for (int i{1}; i <= n; ++i) {
//         for (int j{}; j <= m; ++j) {
//             f[i][j] = f[i - 1][j];
//             if (c[i]) {
//                 for (int k{1}; k <= c[i]; ++k) {
//                     if (j >= k * w[i])
//                         f[i][j] = max(f[i - 1][j], f[i - 1][j - k * w[i]] + k * v[i]);
//                 }
//             } else {
//                 if (j >= w[i])
//                     f[i][j] = max(f[i - 1][j], f[i][j - w[i]] + v[i]);
//             }
//         }
//     }
//     cout << f[n][m] << "\n";

//     return 0;
// }