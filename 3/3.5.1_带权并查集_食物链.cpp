#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 3;
int n, m;
int uf[N], w[N];
char op;
int x, y;

int fd(int x) {
	if (x == uf[x]) return x;
	int t{fd(uf[x])};
	w[x] += w[uf[x]];
	return uf[x] = t;
}

void un(int x, int y, int d) {
	int fx{fd(x)}, fy{fd(y)};
	if (fx == fy) return;
	uf[fx] = fy;
	w[fx] = d + w[y] - w[x]; 
}
bool solve() {
	cin >> op >> x >> y;
	if (x > n || y > n) return false;
	int fx{fd(x)}, fy{fd(y)};
	if (op == '1') {
		if (x == y) return true;
		if (fx == fy && ((w[x] - w[y]) % 3 + 3) % 3 != 0)
			return false;
		un(x, y, 0);
	} else if (op == '2') {
		if (x == y || (fx == fy && ((w[x] - w[y]) % 3 + 3) % 3 != 2))
			return false;
		un(x, y, 2);
	} else {}
	
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i{1}; i <= n; ++i) {
		uf[i] = i;
	}

	int ret{};
	while (m--) {
		if (!solve()) ++ret;
		cout << (7 - m) << " " << ret << "\n";
	}
	cout << ret << "\n"; 

	return 0;
}