#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const int N = 1e4 + 7;
int n;
ull a[N];
const int p = 1e9 + 7;
ull gethash(const string& str) {
	ull ret{};
	for (int i{}; i < str.size(); ++i) {
		int cur(str[i] - '0');
		ret = ret * p + cur;
	}
	return ret;
}

int main() {
	cin >> n;
	string s;
	for (int i{1}; i <= n; ++i) {
		cin >> s;
		a[i] = gethash(s);
	}
	sort(a + 1, a + 1 + n);
	int cnt{1};
	for (int i{1}; i < n; ++i) {
		if (a[i] != a[i + 1]) ++cnt;
	}
	cout << cnt;
	return 0;
}
