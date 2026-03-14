#include <bits/stdc++.h>
using namespace std;

const int N = 18;
const int M = 30;
int n, m;
int tar[M], cur[M];
vector<int> path;
int a[N][M];

int cnt1(int x) {
    int cnt{};
    while (x) {
        x &= (x - 1);
        ++cnt;
    }
    return cnt;
}

int ret;
vector<int> retPath;

void bin_enum() {
    for (int st{}; st < (1 << n); ++st) {
        int v{cnt1(st)};
        if (v >= ret) continue;
        memset(cur, 0, sizeof cur);
        path.clear();
        int tmp{st};
        for  (int i{1}; tmp; ++i, tmp >>= 1) {
            if (tmp & 1) {
                path.emplace_back(i);
                for (int j{1}; j <= m; ++j) {
                    cur[j] += a[i][j];
                }
            }
        }
        for (int i{1}; i <= m; ++i) {
            if (cur[i] < tar[i]) goto next;
        }
        ret = v;
        retPath = path;
        next:;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m;
    for (int i{1}; i <= m; ++i) cin >> tar[i];

    cin >> n;
    // 初始化为n + 1是因为当最后需要全选的时候不会被剪枝剪掉，同时方便查看是否有解（本题保证有解所以不考虑）
    ret = n + 1;
    for (int i{1}; i <= n; ++i)
        for (int j{1}; j <= m; ++j)
            cin >> a[i][j];

    bin_enum();
    cout << ret;
    for (auto& x : retPath) {
        cout << " " << x;
    }
    cout << "\n";

    return 0;
}
