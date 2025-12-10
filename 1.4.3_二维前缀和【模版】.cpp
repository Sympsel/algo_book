#include <bits/stdc++.h>
using namespace std;

const int M = 1005;
int q, n, m;
using ll = long long;

ll a[M][M]{0};
ll dp[M][M]{0};

void solve() {
	for (int i{1}; i <= n; ++i) {
		for (int j{1}; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	
	for (int i{1}; i <= n; ++i) {
		for (int j{1}; j <= m; ++j) {
			dp[i][j] = a[i][j];
			if (i > 1) dp[i][j] += dp[i - 1][j];
			if (j > 1) dp[i][j] += dp[i][j - 1];
			if (i > 1 && j > 1) dp[i][j] -= dp[i - 1][j - 1];
		}
	}
	int x1, y1, x2, y2;
	while (q--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] <<endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> m >> q;
	solve();
	

	return 0;
}