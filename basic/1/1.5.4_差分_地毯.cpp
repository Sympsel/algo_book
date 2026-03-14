#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int n, m;

int d[N][N]{0};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> m;
	
	int x1, y1, x2, y2;
	while (m--) {
		cin >> x1 >> y1 >> x2 >> y2;
		++d[x1][y1]; --d[x2 + 1][y1]; --d[x1][y2 + 1]; ++d[x2 + 1][y2 + 1];
	}
	
	for (int i{1}; i <= n; ++i) {
		for (int j{1}; j <= n; ++j) {
			d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
			cout << d[i][j] << " "; 
		}
		cout << "\n";
	}
	cout << "\n";

	return 0;
}