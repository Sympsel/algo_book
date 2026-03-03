#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
const int M = 103;
int n, m;
int a[N], b[M];

6
6 3 2 4 1 0

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq;
    int x{};
    for (int i{1}; i <= m; ++i) {
        cin >> x;
        pq.emplace(x);
    }

    for (int i{m + 1}; i <= n; ++i) {
        auto t{pq.top()}; pq.pop();
        cin >> x;
        pq.emplace(t + x);
    }

    int ret{};
    while (!pq.empty()) {
        ret = pq.top();
        pq.pop();
    }

    cout << ret << "\n";
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e4 + 7;
// const int M = 103;
// int n, m;
// int a[N], b[M];
// int ret;

// int getmin() {
//     int ret = 0x3f3f3f3f;
//     for (int i{1}; i <= m; ++i) {
//         ret = min(ret, b[i]);
//     }
//     return ret;
// }

// int getmax() {
//     int ret = -0x3f3f3f3f;
//     for (int i{1}; i <= m; ++i) {
//         ret = max(ret, b[i]);
//     }
//     return ret;
// }

// int reduce() {
//     int mi{getmin()};
//     ret += mi;
//     int idx{};
//     for (int i{1}; i <= m; ++i) {
//         b[i] -= mi;
//         if (b[i] == 0) idx = i;
//     }
//     return idx;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n >> m;
//     for (int i{1}; i <= n; ++i) cin >> a[i];
//     for (int i{1}; i <= m; ++i) b[i] = a[i];
//     int pos{m + 1};
//     while (true) {
//         int idx{reduce()};
//         if (pos <= n) {
//             b[idx] = a[pos++];
//         } else {
//             ret += getmax();
//             break;
//         }
//     }

//     cout << ret << "\n";

//     return 0;
// }
