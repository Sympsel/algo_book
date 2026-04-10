#include <bits/stdc++.h>
using namespace std;

const int N = 1007;
int n, m;
int f[N];
int v[N], w[N];

int main() {
	cin >> n >> m;
	for (int i{1}; i <= n; ++i) cin >> v[i] >> w[i];

	for (int i{1}; i <= n; ++i) {
		for (int j{v[i]}; j <= m; ++j) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	cout << f[m] << "\n";

	memset(f, -0x3f, sizeof f);
	f[0] = 0;
	for (int i{1}; i <= n; ++i) {
		for (int j{v[i]}; j <= m; ++j) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	cout << (f[m] < 0 ? 0 : f[m]) << "\n";
	return 0;
}