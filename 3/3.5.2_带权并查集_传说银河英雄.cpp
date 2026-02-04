#include <bits/stdc++.h>
using namespace std;

const int n = 3e4 + 1;
int uf[n];
int d[n];
int cnt[n];

int fd(int x) {
	if (x == uf[x]) return x;
	int t{fd(uf[x])};
	d[x] += d[uf[x]];
	return uf[x] = t;
}

void un(int x, int y) {
	if (x == y) return;
	int fx{fd(x)}, fy{fd(y)};
	if (fx == fy) return;
	uf[fx] = fy;
	d[fx] = cnt[fy];
	cnt[fy] += cnt[fx];
	cnt[fx] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	char op;
	int x, y;
	for (int i{1}; i <= n; ++i) {
		uf[i] = i;
		cnt[i] = 1;
	}

	int t; cin >> t;
	while (t--) {
		cin >> op >> x >> y;
		if (op == 'M') {
			un(x, y);
		} else if (op == 'C') {
			int fx{fd(x)}, fy{fd(y)};
			if (fx == fy) cout << abs(d[y] - d[x]) - 1 << "\n";
			else cout << "-1\n";
		} else {}
	}

	return 0;
}