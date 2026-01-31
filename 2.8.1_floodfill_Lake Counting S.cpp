#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 3;
int n, m;
char a[N][N];
bool b[N][N];
int dx[8]{1, -1, 0, 0, -1, -1, 1, 1};
int dy[8]{0, 0, 1, -1, 1, -1, -1, 1};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i{}; i < n; ++i)
		for (int j{}; j < m; ++j)
			cin >> a[i][j];
	
	int ret{};
	for (int i{}; i < n; ++i) {
		for (int j{}; j < m; ++j) {
			if (a[i][j] == '.' || b[i][j]) continue;
			++ret;
			queue<pair<int, int>> q;
			q.emplace(i, j);
			b[i][j] = true;
			
			while (q.size()) {
				auto [x, y]{q.front()}; q.pop();
				for (int i{}; i < 8; ++i) {
					int r{x + dx[i]}, c{y + dy[i]};
					if (r < 0 || r >= n || c < 0 || c >= m || b[r][c] || a[r][c] == '.')
						continue;
					q.emplace(r, c);
					b[r][c] = true;
				}
			}
		}
	}
	cout << ret << "\n";

	return 0;
}