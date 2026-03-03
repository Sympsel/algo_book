#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int f[N][N];

int sg(int x, int y) {
    if (f[x][y] != -1) return f[x][y];

    unordered_set<int> mp;
    for (int i{2}; i <= x - 2; ++i) mp.emplace(sg(i, y) ^ sg(x - i, y));
    for (int i{2}; i <= y - 2; ++i) mp.emplace(sg(x, i) ^ sg(x, y - i));
    int mex{};
    while (mp.count(mex)) ++mex;
    return f[x][y] = mex;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(f, -1, sizeof f);
    int n, m;
    while (cin >> n >> m) {
        int ret{sg(n, m)};
        if (ret) cout << "WIN\n";
        else cout << "LOSE\n";
    }

    return 0;
}
