#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
using ll = long long;
// int a[N]{0};
ll dif[N]{0};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	// for (int i{1}; i<= n; ++i) {
		// cin >> a[i];
		// dif[i] = a[i] - a[i - 1];
	// }
	int _;
	for (int i{1}; i <= n; ++i) {
		cin >> _;
		dif[i] += _;
		dif[i + 1] -= _;
	}
	
	int l, r, k;
	while (m--) {
		cin >> l >> r >> k;
		dif[l] += k;
		dif[r + 1] -= k;	
	}
	
	for (int i{2}; i <= n; ++i) {
		dif[i] += dif[i - 1];
	}
	
	for (int i{1}; i <= n; ++i) {
		cout << dif[i] << " ";
	}
	cout << "\n";

	return 0;
}