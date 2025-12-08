#include <bits/stdc++.h>
using namespace std;

const int N = 2 * (1e5 + 2);
const int VERY_MIN = -1e9;

int a[N], n;

void solve() {
	a[0] = 0;
	int ret{VERY_MIN};
	int sum{};
	int x;
	for (int i{1}; i <= n; ++i) {
		cin >> x;
		if (i == 1) {
			ret = x;
		}
		sum += x;
		a[i] = min(a[i - 1], sum);
		
		ret = max(sum - a[i - 1], ret);
	}
	cout << ret << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n;
	solve();

	return 0;
}