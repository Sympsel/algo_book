#include <bits/stdc++.h>
using namespace std;

int dx[]{-1,-1,-2,-2, 2, 2, 1, 1};
int dy[]{-2,2,-1,1, 1, -1, 2, -2};
int a, b;
int n, m;
const int N = 407;
int f[N][N];

using pos = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> m >> a >> b;
	--a, --b;
	for (int i{}; i < n; ++i)
		for (int j{}; j < m; ++j)
			f[i][j] = -1;
	
	queue<pos> q;
	q.emplace(a, b);
	f[a][b] = 0;
	
	while (!q.empty()) {
		auto& [x, y]{q.front()}; q.pop();
		for (int i{}; i < 8; ++i) {
			int r{x + dx[i]}, c{y + dy[i]};
			if (r >= 0 && c >= 0 && r < n && c < m && f[r][c] == -1) {
				f[r][c] = f[x][y] + 1;
				q.emplace(r, c);
			}
		}
	}
	for (int i{}; i < n; ++i) {
		for (int j{}; j < m; ++j) {
			cout << f[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	

	return 0;
}