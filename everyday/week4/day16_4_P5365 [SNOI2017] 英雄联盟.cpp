// 背包dp
#include <bits/stdc++.h>
using namespace std;

const int N = 300;
const int M = 6e5;
using ll = long long;
ll f[M];
int n;
ll tar;
int cnt[N], cost[N];
int m{M - 10};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> tar;
    f[0] = 1;
    for (int i{1}; i <= n; ++i) cin >> cnt[i];
    for (int i{1}; i <= n; ++i) cin >> cost[i];

    for (int i{1}; i <= n; ++i) {
        for (int j{m}; j >= 0; --j) {
            for (int k{1}; k <= cnt[i]; ++k) {
                if (j >= k * cost[i])
                    f[j] = max(f[j], f[j - k * cost[i]] * k);
            }
        }
    }

    for (int i{1}; i <= m; ++i) {
        if (f[i] >= tar) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}

// 超级野蛮dfs

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 7;
// using ll = long long;
// struct node {
//     int cnt, cost;
//     node(int _cnt = 0, int _cost = 0) : cnt(_cnt), cost(_cost) {}
//     bool operator<(const node& o) const {
//         return cost < o.cost;
//     }
// }a[N];
// int pos;
// int n;
// ll tar;
// bool solved;

// void dfs(int idx, ll cur, ll ret) {
//     if (cur >= tar) {
//         cout << ret << "\n";
//         solved = true;
//         return;
//     }

//     for (int i{idx}; i <= n; ++i) {
//         auto& [cnt, cost]{a[i]};
//         if (cnt == 0) continue;
//         for (int j{1}; j <= cnt; ++j) {
//             dfs(i + 1, cur * j, ret + cost * j);
//             if (solved) return;
//         }
//     }

// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n >> tar;
//     for (int i{1}; i <= n; ++i) cin >> a[i].cnt;
//     for (int i{1}; i <= n; ++i) cin >> a[i].cost;

//     sort(a + 1, a + n + 1);
//     dfs(1, 1, 0);

//     return 0;
// }
