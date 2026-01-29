#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int n, m;
int a[N][N];
bool b[N][N];
int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};

using pos = pair<int, int>;


bool bfs(int mid) {
	if (n <= 2) return true;
	memset(b, false, sizeof b);
	
	queue<pos> q;
	for (int i{}; i < m; ++i) {
		q.emplace(0, i);
		b[0][i] = true;
	}
	
	while (q.size()) {
		auto& [x, y]{q.front()}; q.pop();
		for (int i{}; i < 4; ++i) {
			int r{x + dx[i]}, c{y + dy[i]};
			if (r > 0 && r < n && c >= 0 && c < m && !b[r][c] && a[x][y] <= mid) {
				if (r == n - 1) return true;
				
				q.emplace(r, c);
				b[r][c] = true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	
	cin >> n >> m;
	
	int l{}, r{};
	for (int i{}; i < n; ++i) {
		for (int j{}; j < m; ++j) {
			cin >> a[i][j];
			r = max(r, a[i][j]);
		}
	}
	
	while (l < r) {
		int mid{(l + r) >> 1};
		if (bfs(mid)) r = mid;
		else l = mid + 1;
	}
	
	cout << l << "\n";

	return 0;
}