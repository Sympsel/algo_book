#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5 * (int)1e4 + 5;

int a[N];
int L, n, m;

ll calc(int d) {
	ll cnt{};
	int i{};
	while (i < n + 1) {
		int j{i + 1};
		while (j < n + 2 && a[j] - a[i] < d) {
			++j;
		}
		cnt += j - i - 1;
		i = j;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	
	cin >> L >> n >> m;
	a[0] = 0;
	for (int i{1}; i <= n; ++i) cin >> a[i];
	a[n + 1] = L;
	
	int l{1}, r{L};
	while (l < r) {
		int mid{l + (r - l) / 2 + 1};
		if (calc(mid) <= m) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	
	cout << l << "\n";

	return 0;
}