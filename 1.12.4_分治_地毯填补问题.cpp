#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, int x, int y, int len) {
	if (len == 1) return;
	int mid{len >> 1};
	
	// dfs(r, c, r + mid - 1, c + mid - 1, mid);
	// dfs(r, c + mid, r + mid - 1, c + mid, mid);
	// dfs(r + mid, c, r + mid, c + mid - 1, mid);
	// dfs(r + mid, c + mid, r + mid, c + mid, mid);
	
	if (x < r + mid && y < c + mid) {
		cout << r + mid << " " << c + mid << " " << "1\n";
		dfs(r, c, x, y, mid);
		dfs(r, c + mid, r + mid - 1, c + mid, mid);
		dfs(r + mid, c, r + mid, c + mid - 1, mid);
		dfs(r + mid, c + mid, r + mid, c + mid, mid);
	} else if (x >= r + mid && y >= c + mid) {
		cout << r + mid - 1 << " " << c + mid - 1 << " " << "4\n";
		dfs(r, c, r + mid - 1, c + mid - 1, mid);
		dfs(r, c + mid, r + mid - 1, c + mid, mid);
		dfs(r + mid, c, r + mid, c + mid - 1, mid);
		dfs(r + mid, c + mid, x, y, mid);
	} else if (x >= r + mid) {
		cout << r + mid - 1 << " " << c + mid << " " << "3\n";
		dfs(r, c, r + mid - 1, c + mid - 1, mid);
		dfs(r, c + mid, r + mid - 1, c + mid, mid);
		dfs(r + mid, c, x, y, mid);
		dfs(r + mid, c + mid, r + mid, c + mid, mid);
	} else {
		cout << r + mid << " " << c + mid - 1 << " " << "2\n";
		dfs(r, c, r + mid - 1, c + mid - 1, mid);
		dfs(r, c + mid, x, y, mid);
		dfs(r + mid, c, r + mid, c + mid - 1, mid);
		dfs(r + mid, c + mid, r + mid, c + mid, mid);
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	
	int k; cin >> k;
	int X, Y; cin >> X >> Y;
	
	dfs(1, 1, X, Y, 1 << k);
	
	return 0;
}