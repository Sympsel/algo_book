#include <bits/stdc++.h>
using namespace std;

int n, m;
using ll = long long;

int cnt;
void dfs(int idx, ll sum, int depth) {
	if (depth == m) {
		if (sum == n) ++cnt;
		return;
	}
	if (sum >= n) return;

	for (int i{idx}; i <= n - sum; ++i) {
		dfs(i, sum + i, depth + 1);
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0, 0);
	cout << cnt << "\n";
	return 0;
}
