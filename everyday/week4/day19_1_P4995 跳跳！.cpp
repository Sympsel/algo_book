#include <bits/stdc++.h>
using namespace std;

const int N = 305;
using ll = long long;
int n;
int a[N];
ll ret;

// 贪心
int main() {
    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    // for (int i{}, j{n}; i < j; ++i, --j) {
    //     cout << pow(a[i] - a[j], 2) << "\n";
    //     ret += pow(a[i] - a[j], 2);
    // }
    int i{}, j{n};
    while (i < j) {
        ret += pow(a[i] - a[j], 2);
        ++i;
        ret += pow(a[i] - a[j], 2);
        --j;
    }
    cout << ret << "\n";
    return 0;
}



// 超时dfs
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 305;
// using ll = long long;
// int n;
// int a[N];
// ll ret;
// ll cur;
// bool st[N];

// void dfs(int u, ll cur) {
//     if (cur > ret) {
//         ret = cur;
//     }

//     for (int i{1}; i <= n; ++i) {
//         if (st[i]) continue;
//         st[i] = true;
//         dfs(i, cur + pow(a[u] - a[i], 2));
//         st[i] = false;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n;
//     for (int i{1}; i <= n; ++i) cin >> a[i];
//     sort(a + 1, a + n + 1);
//     for (int i{1}; i <= n; ++i) {
//         st[i] = true;
//         dfs(i, pow(a[i], 2));
//         st[i] = false;
//     }
//     cout << ret << "\n";

//     return 0;
// }
