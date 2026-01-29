#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int n, m;
int a[N][N];
int dx[4]{0, 0, 1, -1};
int dy[4]{1, -1, 0, 0};

using pos = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> m;
	char x;
	queue<pos> q;
	for (int i{}; i < n; ++i) {
		for (int j{}; j < m; ++j) {
			cin >> x;
			if (x == '0') a[i][j] = -1;
			else q.emplace(i, j);
		}
	}
	
	int ret{};
	while (q.size()) {
		int sz(q.size());
		++ret;
		while (sz--) {
			auto& [x, y]{q.front()}; q.pop();
			for (int i{}; i < 4; ++i) {
				int r{x + dx[i]}, c{y + dy[i]};
				if (r < 0 || r >= n || c < 0 || c>= m || a[r][c] >= 0) continue;
				a[r][c] = ret;
				q.emplace(r, c);
			}
		}
	}
	
	for (int i{}; i < n; ++i) {
		for (int j{}; j < m; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	return 0;
}