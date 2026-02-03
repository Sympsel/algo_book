#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 3;
int n, m, p;
int x, y;
int a[N];

int fd(int _) {
	return a[_] == _ ? _ : a[_] = fd(a[_]);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> m >> p;
	for (int i{1}; i <= n; ++i) a[i] = i;

	while (m--) {
		cin >> x >> y;
		a[fd(x)] = fd(y);	
	}

	while (p--) {
		cin >> x >> y;
		if (fd(x) == fd(y)) cout << "Yes\n";
		else cout << "No\n";
	}
	

	return 0;
}