#include <bits/stdc++.h>
using namespace std;

const int N = 110;
const int M = 1e3 + 7;
int f[M];
int t[N], w[N];
int n, m;

int main() {
	cin >> m >> n;
	for (int i{1}; i <= n; ++i) cin >> t[i] >> w[i];

	for (int i{1}; i <= n; ++i) {
		for (int j{m}; j >= t[i]; --j) {
			f[j] = max(f[j], f[j - t[i]] + w[i]);
		}
	}
	cout << f[m] << "\n";
	return 0;
}