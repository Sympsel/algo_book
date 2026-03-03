#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
int n, m;
int a[N];
vector<int> path;
bool solved;

void dfs(int idx, int sum) {
    if (solved || sum > m) return;
    if (sum == m) {
        solved = true;
        for (int i{}; i < path.size(); ++i) {
            if (i > 0) cout << " ";
            cout << path[i];
        }
        return;
    }

    for (int i{idx}; i <= n; ++i) {
        if (i > idx && a[i] == a[i - 1]) continue;
        path.emplace_back(a[i]);
        dfs(i + 1, sum + a[i]);
        if (solved) return;
        path.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i{1}; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);

    dfs(1, 0);
    if (!solved) cout << "No Solution\n";
    return 0;
}
