#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 7;
const int p = 2333;
int f[N][N];
int n, m;

inline void read(int& x) {
	char c(getchar());
	while (c < '0' || c > '9') c = getchar();
	x = c - '0';
}

int main() {
	cin >> n >> m;
	int flag;
	for (int i{n}; i >= 1; --i) {
		for (int j{1}; j <= m; ++j) {
			read(flag);
			if (flag) f[i][j] = -1;
		}
	}
		
	f[1][0] = 1;
	for (int i{1}; i <= n; ++i) {
		for (int j{1}; j <= m; ++j) {
			if (f[i][j] == -1) continue;
			int sum{};
			if (f[i - 1][j] != -1) sum = (f[i - 1][j] + sum) % p;
			if (f[i][j - 1] != -1) sum = (f[i][j - 1] + sum) % p;
			f[i][j] = sum;
		}
	}
	cout << (f[n][m] == -1 ? 0 : f[n][m]) << "\n";
	return 0;
}
