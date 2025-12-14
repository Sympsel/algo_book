#include <bits/stdc++.h>
using namespace std;

const int N = 200003;
using ll = long long;

ll a[N]{};
int n, c;

int getCnt(int b, int e, int d) {
	int l{b}, r{e};
	while (l < r) {
		int mid{l + (r - l) / 2};
		if (a[mid] >= d) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if (a[l] != d) {
		return 0;	
	}
	int _{l};
	
	l = b, r = e;
	while (l < r) {
		int mid{l + (r - l) / 2 + 1};
		if (a[mid] <= d) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return l - _ + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> c;
	for (int i{}; i < n; ++i) {
		cin >> a[i];
	}
	
	sort(a, a + n);
	
	ll ret{};
	for (int i{1}; i < n; ++i) {
		ll t(a[i] - c);
		ret += getCnt(0, i - 1, t);
	}
	cout << ret << "\n";

	return 0;
}