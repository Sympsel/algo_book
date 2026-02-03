#include <bits/stdc++.h>
using namespace std;

int times{3}; 

#define N 15

bool col[N + 1], st1[2 * N + 1], st2[2 * N + 1];

vector<int> path;
int n;
int ret;

void dfs(int row) {
	if (row == n + 1) {
		if (times-- > 0) {
			for (int& _ : path) {
				cout << _ << " ";
			}
			cout << "\n";
		}
		++ret;
		return;
	}
	
	
	for (int i{1}; i <= n; ++i) {
		if (col[i] || st1[i - row + n] || st2[i + row]) continue;
		path.emplace_back(i);
		col[i] = st1[i - row + n] = st2[i + row] = true;
		dfs(row + 1);
		path.pop_back();
		col[i] = st1[i - row + n] = st2[i + row] = false;
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	dfs(1);
	cout << ret << "\n";

	return 0;
}