#include <bits/stdc++.h>
using namespace std;

const int N = 103;
int n, m;
char a[N][N];
int uf[N * N];
int dx[4]{1, 1, 1, 0};
int dy[4]{-1, 0, 1, 1};
using pos = pair<int, int>;
int fd(int x) {
	return uf[x] == x ? x : uf[x] = fd(uf[x]);
}

void un(int x, int y) {
	if (x != y) {
		uf[fd(x)] = fd(y);	
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i{}; i < n * m; ++i)	uf[i] = i;
	for (int i{}; i < n; ++i)
		for (int j{}; j < m; ++j)
			cin >> a[i][j];

	for (int i{}; i < n; ++i) {
		for (int j{}; j < m; ++j) {
			if (a[i][j] == '.') continue;

			for (int k{}; k < 4; ++k) {
				int r{i + dx[k]}, c{j + dy[k]};
				if (c < 0 || a[r][c] != 'W') continue;

				un(i * m + j, r * m + c);					
			}
		}
	}	
	int ret{};
	for (int i{}; i < m * n; ++i) {
		if (a[i / m][i % m] == 'W' && uf[i] == i)
			++ret;
	}
	cout << ret << "\n";
	return 0;
}