#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
string base;
using ull= unsigned long long;
int n;
const int mod = 131;
ull p[N];
ull f[N];

void init() {
	p[0] = 1;
	for (int i{1}; i <= n; ++i) {
		f[i] = f[i - 1] * mod + base[i];
		p[i] = p[i - 1] * mod;
	}
}

inline ull gethash(int l, int r) {
	return f[r] - f[l - 1] * p[r - l + 1]; 
}

bool solve() {
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	if (r1 - l1 != r2 - l2) return false;
	if (gethash(l1, r1) == gethash(l2, r2)) return true;
	return false;
}

int main() {
	cin >> base;
	n = base.size();
	base = " " + base;
	init();
	int t; cin >> t;
	while (t--) {
		if (solve()) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
