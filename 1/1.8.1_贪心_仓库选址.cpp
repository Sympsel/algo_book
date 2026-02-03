#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;
int a[N], n;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; ++i) cin >> a[i];
	
	sort(a, a + n);
	
	
	ll ret{};
	// int mid{(n - 1) / 2};
	// for (int i{}; i < n; ++i) ret += abs(a[i] - a[mid]);
	for (int i{}; i < n / 2; ++i) ret += abs(a[i] - a[n - i - 1]);
	cout << ret << "\n";

	return 0;
}