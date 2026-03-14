#include <bits/stdc++.h>
using namespace std;

#define N 103
int a[N][N];
int row, col;
int dx[4]{0,0,1,-1};
int dy[4]{-1,1,0,0};
int f[N][N];


int dfs(int r, int c) {
	if (f[r][c] != 0) return f[r][c];
	int ret{};
	for (int i{}; i < 4; ++i) {
		int x{r + dx[i]}, y{c + dy[i]};
		
		if (x >= 0 && x < row && y >= 0 && y < col && a[r][c] > a[x][y]) {
			ret = max(ret, dfs(x, y));
		}
	}
	return f[r][c] = ret + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> row >> col;
	for (int i{}; i < row; ++i)
		for (int j{}; j < col; ++j)
			cin >> a[i][j];
			
	int ret{};
	for (int i{}; i < row; ++i)
		for (int j{}; j < col; ++j)
			ret = max(ret, dfs(i, j));
			
	cout << ret << "\n";

	return 0;
}