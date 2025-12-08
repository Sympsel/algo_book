#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 7;

int n, t;
ll s[N]{};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> t;
	for (int i{1}; i <= n; ++i) {
		cin >> s[i];
		s[i] += s[i - 1];
	}
	int l, r;
	while (t--) {
		cin >> l >> r;
		cout << s[r] - s[l - 1] << "\n";	
	}
	return 0;
}