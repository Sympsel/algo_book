#include <bits/stdc++.h>
using namespace std;

const int N = 3e4 + 3;
int w, n;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> w >> n;
	for (int i{}; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	
	int i{}, j{n - 1};
	int ret{};
	while (i <= j) {
		if (a[i] + a[j] > w) {
			--j;
		} else {
			++i;
			--j;
		}
		++ret;
	}
	
	cout << ret << "\n";
	return 0;
}