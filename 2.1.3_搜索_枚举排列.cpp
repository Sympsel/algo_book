#include <bits/stdc++.h>
using namespace std;

#define N 13
int n, k;
vector<int> path;
bool a[N];

void dfs() {
	if (path.size() == k) {
		for (int& _ : path) {
			cout << _ << " ";
		}
		cout << "\n";
		return;
	}
	
	for (int i{1}; i <= n; ++i) {
		if (!a[i]) {
			path.emplace_back(i);
			a[i] = true;
			dfs();
			path.pop_back();
			a[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> k;
	dfs();

	return 0;
}