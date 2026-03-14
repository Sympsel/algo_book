#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;
int n, m;
int a[N];

int fd(int x) {
	return a[x] == x ? x : a[x] = fd(a[x]);
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i{1}; i <= n; ++i) a[i] = i;
	
	int op{};
	int x{}, y{};
	while (m--) {
		cin >> op >> x >> y;
		if (op == 1) {
			a[fd(x)] = fd(y);
		} else {
			if (fd(x) == fd(y))
				cout << "Y\n";
			else cout << "N\n";
		}
	}
	

	return 0;
}