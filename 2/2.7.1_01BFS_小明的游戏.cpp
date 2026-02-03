#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 7;
int n, m;
char a[N][N];
int dist[N][N];
int dx[4]{-1, 1, 0, 0};
int dy[4]{0, 0, 1, -1};
int sx, sy, tx, ty;
using pos = pair<int, int>;


int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	while (cin >> n >> m, n && m) {
		memset(dist, -1, sizeof dist);
		
		for (int i{}; i < n; ++i)
			for (int j{}; j < m; ++j)
				cin >> a[i][j];
		cin >> sx >> sy >> tx >> ty;
		if (sx == tx && sy == ty) {
			cout << "0\n";
			continue;
		}
		
		deque<pos> q;
		q.emplace_back(sx, sy);
		dist[sx][sy] = 0;
		
		while (!q.empty()) {
			auto [x, y]{q.front()}; q.pop_front();
			if (x == tx && y == ty) {
				cout << dist[tx][ty] << "\n";
				break;
			}
			
			for (int i{}; i < 4; ++i) {
				int r{x + dx[i]}, c{y + dy[i]};
				if (r < 0 || r >= n || c < 0 || c >= m) continue;
				
				int d{dist[x][y] + (a[r][c] == a[x][y] ? 0 : 1)};
				if (dist[r][c] == -1) {
					dist[r][c] = d;
					if (a[r][c] == a[x][y]) q.emplace_front(r, c);
					else q.emplace_back(r, c);
				} else if (d < dist[r][c]) {
					dist[r][c] = d;
				}
			}
		}
	}

	return 0;
}