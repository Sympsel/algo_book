#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e6 + 3;
const int H = (int)1e5 * 4;

int n, m;
int a[N];

ll calc(int h) {
	ll cnt{};
	for (int i{}; i < n; ++i) {
		cnt += max(0, a[i] - h);
		if (cnt >= m) {
			return cnt;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i{}; i < n; ++i) cin >> a[i];
	
	int l{}, r{H};
	while (l < r) {
		int mid{l + (r - l) / 2 + 1};
		if (calc(mid) >= m) l = mid;
		else r = mid - 1;
	}
	
	cout << l << "\n";

	return 0;
}