#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int a[N];
int n, m;

int c[N];
int ret;
int cnt;
void dfs(int bg) {
	if (cnt >= ret) return;
	if (bg > n) {
		ret = cnt;
		return;
	}

	for (int i{1}; i <= cnt; ++i) {
		if (c[i] + a[bg] <= m) {
			c[i] += a[bg];
			dfs(bg + 1);
			c[i] -= a[bg];
		}
	}
	++cnt;
	c[cnt] = a[bg];
	dfs(bg + 1);
	c[cnt] = 0;
	--cnt;
}

int main() {
	cin >> n >> m;
	ret = n;
	for (int i{1}; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n, [](const int& x, const int& y) {
		return x > y;
	});
	dfs(1);
	cout << ret << "\n";
	return 0;
}