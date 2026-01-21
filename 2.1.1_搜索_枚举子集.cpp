#include <bits/stdc++.h>
using namespace std;

int n;
string path;

void dfs(int depth) {
	if (depth == n) {
		cout << path << "\n";
		return;
	}
	path += "N";
	dfs(depth + 1);
	path.pop_back();
	
	path += "Y";
	dfs(depth + 1);
	path.pop_back();
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	
	dfs(0);

	return 0;
}