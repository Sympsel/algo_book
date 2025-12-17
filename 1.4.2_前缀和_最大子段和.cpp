#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5;
const ll MIN_ = -1e18;
ll f[N], n;

int main() {
	cin >> n >> f[0];
	for (int i{1}; i < n; ++i) {
		cin >> f[i];
		f[i] += f[i - 1];
	}
	
	ll prevmin{0};
	ll ret{MIN_};
	for (int i{}; i < n; ++i) {
		ret = max(ret, f[i] - prevmin);
		prevmin = min(f[i], prevmin);
	}
	
	cout << ret << "\n";
	return 0;
}