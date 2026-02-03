#include <bits/stdc++.h>
using namespace std;

const int N = 33;

int n;
int a[N][N];
bool b[N][N];
int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};
using pos = pair<int, int>;

void bfs(int x, int y) {
	queue<pos> q;
	q.emplace(x, y);
	b[x][y] = true;
	
	while (q.size()) {
		auto [i, j]{q.front()}; q.pop();
		
		for (int k{}; k < 4; ++k) {
			int r{i + dx[k]}, c{j + dy[k]};
			if (r < 0 || r >= n || c < 0 || c >= n || b[r][c] || a[r][c] != 0) continue;
			q.emplace(r, c);
			b[r][c] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n;
	for (int i{}; i < n; ++i)
		for (int j{}; j < n; ++j)
			cin >> a[i][j];
	
	for (int i{}; i < n; ++i) {
		if (a[0][i] == 0)
			bfs(0, i);
		if (a[n - 1][i] == 0)
			bfs(n - 1, i);
	}
	
	for (int i{1}; i < n - 1; ++i) {
		if (a[i][0] == 0)
			bfs(i, 0);
		if (a[i][n - 1] == 0)
			bfs(i, n - 1);
	}
	
	for (int i{1}; i < n - 1; ++i)
		for (int j{1}; j < n - 1; ++j)
			if (a[i][j] == 0 && b[i][j] == false)
				a[i][j] = 2;
	
	for (int i{}; i < n; ++i) {
		for (int j{}; j < n; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	
	return 0;
}
