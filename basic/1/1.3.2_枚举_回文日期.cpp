#include <bits/stdc++.h>
using namespace std;

int table[13]{
	-1, 31,28,31,30,31,30,31,31,30,31,30,31
};

int md(int y, int m) {
	if (m == 2 && (y % 400 == 0 || (y % 4 == 0 || y % 100 != 0))) {
		return 29;
	}
	return table[m];
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int b, e;
	int cnt{};
	cin >> b >> e;
	for (int i{b}; i <= e; ++i) {
		int y{i / 10000};
		int m{i / 100 % 100};
		int d{i % 100};
		if (d <= 0 || d > md(y, m) || m <=0 || m > 12) {
			continue;
		}
		if (i / 10000000 == i % 10
			&& i / 1000000 % 10 == i / 10 % 10
			&& i / 100000 % 10 == i / 100 % 10
			&& i / 10000 % 10 == i / 1000 % 10) {
				++cnt;
			}
	}
	cout << cnt << "\n";

	return 0;
}