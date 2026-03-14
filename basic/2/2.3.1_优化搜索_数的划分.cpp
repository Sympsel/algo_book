#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k;
ll ret;
vector<int> ps;

void dfs(int depth, int x) {
	if (depth == k) {
		if (ps.back() == n)
			++ret;
		return;
	}
	
	// if (path.back() + x * (k - depth) > n) return;
	
	for (int i{x}; i <= n; ++i) {
		if (ps.back() + i * (k - depth) > n) return;
		ps.emplace_back(ps.back() + i);
		dfs(depth + 1, i);
		ps.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> k;
	ps.emplace_back(0);
	dfs(0, 1);
	cout << ret << "\n";

	return 0;
}