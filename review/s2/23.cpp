#include <bits/stdc++.h>
using namespace std;

int f[410][410];
bool st[410][410];
int n, m;

int dx[]{1, 2, -1, -2, 1, 2, -1, -2};
int dy[]{2, 1, -2, -1, -2, -1, 2, 1};

int s, t;
int main() {
	cin >> n >> m >> s >> t;
	memset(f, -1, sizeof f);
	queue<pair<int, int>> q;
	q.emplace(s, t);
	f[s][t] = 0;
	st[s][t] = true;
	while (q.size()) {
		auto [x, y]{q.front()}; q.pop();
		for (int i{}; i < 8; ++i) {
			int r{x + dx[i]}, c{y + dy[i]};
			if (r < 1 || r > n || c < 1 || c > m) continue;
			if (st[r][c]) continue;
			f[r][c] = f[x][y] + 1;
			q.emplace(r, c);
			st[r][c] = true;
		}
	}
	for (int i{1}; i <= n; ++i) {
		for (int j{1}; j <= m; ++j) {
			cout << f[i][j] << " \n"[j == m];
		}
	}
	return  0;
}
