#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const int N = 1e6 + 5;
string s;
int m;
ull f[N];
ull p[N];
const int mod = 131;

void init() {

	cin >> s >> m;
	s = "_" + s;
	p[0] = 1;
	for (int i{1}; i < s.size(); ++i) {
		f[i] = f[i - 1] * mod + s[i];
		p[i] = mod * p[i - 1];
	}
}

ull get_hash(int& l, int& r) {
	return f[r] - f[l - 1] * p[r - l + 1];
}

void solve(int l1, int r1, int l2, int r2) {
	if (get_hash(l1, r1) == get_hash(l2, r2)) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	init();
	int l1, r1, l2, r2;
	while (m--) {
		cin >> l1 >> r1 >> l2 >> r2;
		solve(l1, r1, l2, r2);
	}

	return 0;
}
