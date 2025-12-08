#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N], b[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int i{1}; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i{1}; i <= n; ++i) {
		cin >> b[i];
	}
	
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	
	int ret{};
	for (int i{1}, j{1}; i <= n; ++i) {
		if (a[i] > b[j]) {
			++j;
		} else {
			++ret;
		}
	}
	cout << ret << "\n";

	return 0;
}