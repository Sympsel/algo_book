#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 7;
int n, k;
char op;
int uf[N * 3];

int fd(int x) {
	return uf[x] == x ? x : uf[x] = fd(uf[x]);
}

void un(int x, int y) {
	if (x != y) uf[fd(y)] = fd(x);
}

bool issame(int x, int y) {
	return x == y ? true : fd(x) == fd(y);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i{1}; i <= n * 3; ++i) uf[i] = i;
	int ret{};
	int x, y;
	while (k--) {
		cin >> op >> x >> y;
		if (x > n || y > n) {
			++ret;
			continue;
		}
		if (op == '1') {
			if (issame(x, y + n) || issame(y, x + n)) {
				++ret;
				continue;
			}
			un(x, y);
			un(x + n, y + n);
			un(x + 2 * n, y + 2 * n);
		} else if (op == '2') {
			if (issame(x, y) || issame(y, x + n)) {
				++ret;
				continue;
			}
			
			un(x, y + n);
			un(y, x + 2 * n);
			un(x + n, y + 2 * n);
			
		} else {}
	}	
	cout << ret << "\n";

	return 0;
}
