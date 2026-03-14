#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> path;

void dfs(int k) {
	if (path.size() == m) {
		for (int& _ : path) {
			cout << _ << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i{k + 1}; i <= n; ++i) {
		path.emplace_back(i);
		dfs(i);
		path.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> m;
	
	dfs(0);

	return 0;
}