#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int n, m;
using  ll = long long;

ll f[N];
int v[N], w[N];

int main() {
	cin >> n >> m;
	for (int i{1}; i <= n; ++i) cin >> v[i] >> w[i];
	for (int i{1}; i <= n; ++i) {
		for (int j{m}; j >= v[i]; --j) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	cout << f[m] << "\n";
	memset(f, -0x3f, sizeof f);
	f[0] = 0;
	for (int i{1}; i <= n; ++i) {
		for (int j{m}; j >= v[i]; --j) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	cout << (f[m] < 0 ? 0 : f[m]) << "\n";

	return 0;
}
