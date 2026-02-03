#include <bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int cnt{};
	int year;
	while (cin >> year) {
		int a{year / 1000}, b{year / 100 % 10}, c{year / 10 % 10}, d{year % 10};
		if (a == c && b + 1 == d) {
			++cnt;
		}
	}
	cout << cnt << "\n";

	return 0;
}