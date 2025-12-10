#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 3;

int n, m, q;
ll d[N][N]{0};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> m >> q;
	
	int val;
	for (int i{1}; i <= n; ++i) {
		for (int j{1}; j <= m; ++j) {
			cin >> val;
			d[i][j] += val;
			d[i + 1][j] -= val;
			d[i][j + 1] -= val;
			d[i + 1][j + 1] += val;
		}
	}
	
	int x1, y1, x2, y2, k;
	while (q--) {
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		d[x1][y1] += k, d[x2 + 1][y1] -= k, d[x1][y2 + 1] -= k, d[x2 + 1][y2 + 1] += k;
	}
	
	for (int i{1}; i <= n; ++i) {
		for (int j{1}; j <= m; ++j) {
			d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	return 0;
}