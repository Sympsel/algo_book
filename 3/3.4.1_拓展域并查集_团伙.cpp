#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
int uf[N * 2];
int n, m, x, y;
char r;

int fd(int x) {
	return uf[x] == x ? x : uf[x] = fd(uf[x]);
}

void un(int x, int y) {
	if (x != y) uf[fd(y)] = fd(x);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i{1}; i <= n * 2; ++i) uf[i] = i;
	while (m--) {
        
		cin >> r >> x >> y;
        if (r == 'E') {
			un(x, y + n);
			un(y, x + n);
		} else {
			un(x, y);
		}
	}

	int ret{};
	for (int i{1}; i <= n; ++i) {
		if (uf[i] == i) ++ret;
	}
	cout << ret << "\n";

	return 0;
}
