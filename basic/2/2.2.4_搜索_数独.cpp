#include <bits/stdc++.h>
using namespace std;

int a[10][10];

// [行号或列号][某数是否存在]     // [块行编号][块列编号][某数是否存在]
bool row[10][10], col[10][10], st[3][3][10];

bool isSolved;

void dfs(int r, int c) {
	if (c == 10) {
		dfs(r + 1, 1);
		return;
	}

	if (r == 10) {
		for (int i{1}; i < 10; ++i) {
			for (int j{1}; j < 10; ++j) {
				cout << a[i][j] << " ";
			}	
			cout << "\n";
		}
		cout << "\n";
		isSolved = true;
		return;
	}
	
	if (a[r][c]) {
		dfs(r, c + 1);
		return;
	}

	for (int i{1}; i < 10; ++i) {
		if (row[r][i] || col[c][i] || st[(r - 1) / 3][(c - 1) / 3][i]) continue;
		
		a[r][c] = i;
		row[r][i] = col[c][i] = st[(r - 1) / 3][(c - 1) / 3][i] = true;
		dfs(r, c + 1);
		if (isSolved) {
			return;
		}
		a[r][c] = 0;
		row[r][i] = col[c][i] = st[(r - 1) / 3][(c - 1) / 3][i] = false;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int x;
	for (int i{1}; i < 10; ++i)
		for (int j{1};j < 10; ++j) {
			cin >> x;
			if (x) {
				a[i][j] = x;
				row[i][x] = col[j][x] = st[(i - 1) / 3][(j - 1) / 3][x] = true;
			}
		}
		
	dfs(1, 1);
	

	return 0;
}