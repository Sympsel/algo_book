#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 3;
using ull = unsigned long long;
const int p = 131;
int n;
ull a[N];

ull get_hash(string& s) {
	ull ret{};
	for (int i{1}; i <= s.size(); ++i)
		ret = ret * p + s[i - 1];
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	string s;
	for (int i{1}; i <= n; ++i) {
		cin >> s;
		a[i] = get_hash(s);
	}

	sort(a + 1, a + 1 + n);
	int ret{1};
	for (int i{2}; i <= n; ++i) {
		if (a[i] != a[i - 1]) ++ret;
	}
	cout << ret << "\n";

	return 0;
}