#include <bits/stdc++.h>
using namespace std;

// 快速选择算法

const int N = 5e7 + 7;
int n, k;
int a[N];

int quickSelect(int b, int e) {
	if (b >= e) return a[b];
	
	int l{b}, r{e};
	int c{b + 1};
	int p{a[b]};
	while (c <= r) {
		if (a[c] < p) {
			swap(a[c], a[l]);
			++l;
			++c;
		} else if (a[c] > p) {
			swap(a[c], a[r]);
			--r;
		} else {
			++c;
		}
	}
	
	if (k < l) {
		return quickSelect(b, l - 1);
	}
	if (k <= r) {
		return p;
	}
	return quickSelect(r + 1, e);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i{}; i < n; ++i) cin >> a[i];
	
	cout << quickSelect(0, n - 1) << "\n";
	return 0;
}