#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n;
vector<int> path;

void dfs(int idx, int sum) {
    if (sum > n) return;
    if (sum == n) {
        int sz(path.size());
        for (int i{}; i < sz; ++i) {
            if (i > 0) cout << "+";
            cout << path[i];
        }
        cout << "\n";
        return;
    }
    for (int i{idx}; i < n; ++i) {
        path.emplace_back(i);
        dfs(i, sum + i);
        path.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dfs(1, 0);
    return 0;
}
