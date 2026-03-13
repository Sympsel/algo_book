#include <bits/stdc++.h>
using namespace std;

const int N = 23;
int w[N];
bool st[N][N];
int n;

int ret{};
vector<int> path;
vector<int> retPath;

int cnt{};
void dfs(int idx) {
    if (ret < cnt) {
        retPath = path;
        ret = cnt;
    }
    for (int i{idx + 1}; i <= n; ++i) {
        if (!st[idx][i]) continue;
        path.emplace_back(i);
        cnt += w[i];
        dfs(i);
        path.pop_back();
        cnt -= w[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i{1}; i <= n; ++i) cin >> w[i];
    for (int i{1}; i <= n; ++i) {
        for (int j{i + 1}; j <= n; ++j) {
            cin >> st[i][j];
        }
    }

    for (int i{1}; i <= n; ++i) {
        path.clear();
        cnt = 0;

        path.emplace_back(i);
        cnt += w[i];
        dfs(i);
    }
    for (auto& x : retPath) {
        cout << x << " ";
    }
    cout << "\n" << ret << "\n";

    return 0;
}
