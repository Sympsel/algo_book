#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int a[N], n;
using ll = long long;

const int _MIN = -0x7fffffff;

ll dfs(int b, int e) {
	if (b == e) return a[b];
	
	int mid{((e - b) >> 1) + b};
	ll ret{max(dfs(b, mid), dfs(mid + 1, e))};
	
	ll sl{}, sr{};
	ll slm{_MIN}, srm{_MIN};
	for (int i{mid}; i >= b; --i) {
		sl += a[i];
		slm = max(slm, sl);
	}
	
	for (int i{mid + 1}; i <= e; ++i) {
		sr += a[i];
		srm = max(srm, sr);
	}
	return max(ret, slm + srm);
	
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; ++i) cin >> a[i];
	
	cout << dfs(0, n - 1) << "\n";

	return 0;
}