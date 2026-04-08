#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
const int INF = 0x3f3f3f3f;
int n, m;
string a[N];

int f[N][N];
bool vis[N][N];
int dx[]{1, -1, 0, 0};
int dy[]{0, 0, 1, -1};
using pii = pair<int, int>;

void expend(char ch) {
	deque<pii> q;
	int num(ch - '0');
	for (int i{}; i < n; ++i) {
		for (int j{}; j < m; ++j) {
			if (a[i][j] == ch) {
				q.emplace_back(i, j);
				f[num][i][j] = 0;
			}
		}
	}

	while (q.size()) {
		auto [x, y]{q.front()}; q.pop_front();
		for (int i{}; i < 4; ++i) {
			int r{x + dx[i]}, c{y + dy[i]};
			if (r < 0 || r >= n || c < 0 || c >= m || f[num][r][c] == ch || f[num][r][c] == '#') continue;
			int w{f[num][r][c] == '.' ? 1 : 0};
			// if (f[num][r][c] == -1) {
			if (vis[i][j] == false) {
				f[num][r][c] = f[num][x][y] + w;
				if (w == 0) q.emplace_front(r, c);
				else q.emplace_back(r, c);
			} else if (f[num][x][y] + w < f[num][r][c]) {
				f[num][r][c] = f[num][x][y] + w;
			} else {}
		}
	}
}

int main() {
	cin >> n >> m;
	memset(f, -1, sizeof f);
	for (int i{}; i < n; ++i) cin >> a[i];
	expend('1');
	expend('2');
	expend('3');
	int ret{INF};
	for (int i{}; i < n; ++i) {
		for (int j{}; j < m; ++j) {
			ret = min(ret, f[1][i][j] + f[2][i][j] + f[3][i][j]);
		}
	}
	if (ret == INF) cout << "-1\n";
	else cout << ret << "\n"; 
}
