#include <bits/stdc++.h>
using namespace std;

int n, m, k;
const int N = 20;
using ll = long long;

int a[N][N];
int b[N][N];
int row[N]{}, col[N]{};

int cnt1(int x) {
	int cnt{};
	while (x) {
		x &= x - 1;
		cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	k = min(k, m + n);
	for (int i{}; i < n; i++)
		for (int j{}; j < m; j++)
			cin >> a[i][j];
	
	ll ret{};
	for (int st{}; st < (1 << m); st++) {
		memcpy(b, a, sizeof a);
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);
		int c{cnt1(st)};
		// cout << "c: " << c << "\n";
		if (c > k) continue;
		int r{k - c};
		
		for (int j{}; j < m; j++) {
			if ((st >> j) & 1 == 1) {
				for (int k{}; k < n; k++) {
					col[j] += b[k][j];
					b[k][j] = 0;
				}
			}
		}
		
		// for (int i{}; i < n; i++) {
			// for (int j{}; j < m; j++) {
				// cout << b[i][j] << " ";
			// }
			// cout << "\n";
		// }
		// cout << "\n";
			
		
		for (int j{}; j < n; j++)
			for (int k{}; k < m; k++)
				row[j] += b[j][k];
		
		sort(row, row + n, [](const int& a, const int& b) {return a > b;});
		ll sum{};
		for (int i{}; i < r; i++) sum += row[i];
		for (int i{}; i < m; i++) sum += col[i];
		// cout << "row: ";
		// for (int i{}; i < n; i++) cout << row[i] << " ";
		// cout << "\n";
		// cout << "col: ";
		// for (int i{}; i < m; i++) cout << col[i] << " ";
		// cout << "\n"; 
		// cout << "sum: " << sum << "\n";
		ret = max(ret, sum);
		
	}
	cout << ret << "\n";

	return 0;
}