#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5001;
int n, m;
int v[N][N]{0};
ll dp[N][N]{0};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> m;
	int x, y, _;
	while (n--) {
		cin >> x >> y;
		cin >> _;
		v[x][y] += _;
	}
	
	for (int i{}; i < N; ++i) {
		for (int j{}; j < N; ++j) {
			dp[i][j] += v[i][j];
			if (i > 0) dp[i][j] += dp[i - 1][j];
			if (j > 0) dp[i][j] += dp[i][j - 1];
			if (i > 0 && j > 0) dp[i][j] -= dp[i - 1][j - 1];
		}
	}
	
	ll maxV{};
	for (int i{m - 1}; i < N; ++i) {
		for (int j{m - 1}; j < N; ++j) {
			ll temp = dp[i][j];
			if (i > m - 1) temp -= dp[i - m][j];
			if (j > m - 1) temp -= dp[i][j - m];
			if (i > m - 1 && j > m - 1)
				temp += dp[i - m][j - m];
			maxV = max(temp, maxV);
		}
	}
	cout << maxV << endl;
	

	return 0;
}