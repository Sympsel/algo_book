#include <bits/stdc++.h>
using namespace std;

const int N = 13;
int n;
vector<int> path;
bool a[N];

void dfs() {
	if (path.size() == n) {
		for (int& _ : path) {
			cout << std::right << setw(5) << _;
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

	cin >> n;
	dfs();

	return 0;
}