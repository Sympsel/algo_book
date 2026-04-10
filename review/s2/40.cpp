#include <bits/stdc++.h>
using namespace std;

const int N = 1007;
int n, m;
int f[N];
int w[N], v[N], c[N];

int main() {
	cin >> m >> n;
	for (int i{1}; i <= n; ++i) {
		cin >> w[i] >> v[i] >> c[i];
	}
	for (int i{1}; i <= n; ++i) {
		for (int j{m}; j >= 0;  --j) {
			for (int k{1}; k <= c[i]; ++k) {
				f[j] = max(f[j], f[j - k * w[i]] + v[i]);
			}
		}
	}
	cout << f[m] << "\n";
	return 0;
}
