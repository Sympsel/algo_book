#include <queue>
#include <iostream>
using namespace std;

#define N 33

int x0, y0, n, m;
char a[N][N];
bool b[N][N];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

using pos = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >>m;
	for (int i{}; i < n; ++i) {
		for (int j{}; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'k')
				x0 = i, y0 = j;
		}
	}
	
	int cnt{}, step{};
	bool isSolved{false};
	
	queue<pos> q;
	q.emplace(x0, y0);
	b[x0][y0] = true;
	
	
	while (q.size()) {
		int sz(q.size());
		if (!isSolved) {
			++step;
		}
		while (sz--) {
			auto& [x, y]{q.front()}; q.pop();
			for (int i{}; i < 4; ++i) {
				int r{x + dx[i]}, c{y + dy[i]};
				if (r < 0 || c < 0 || r >= n || c >= m || b[r][c] || a[r][c] == '*') continue;
				if (a[r][c] == 'e') {
					if (!isSolved) {
						isSolved = true;
					}
					++cnt;
				} else {
					q.emplace(r, c);
				}
				b[r][c] = true;
			}
		}
	}
	
	if (isSolved)
        cout << cnt << " " << step << "\n";
    else 
        cout << "-1\n";
	return 0;
}