#include <bits/stdc++.h>
using namespace std;

int m, n, k, l, d;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	set<int> rows;
	set<int> cols;
	cin >> m >> n >> k >> l >> d;
	int x1, y1, x2, y2;
	for (int i{}; i < d; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) {
			cols.emplace(min(y1, y2));
		} else {
			rows.emplace(min(x1, x2));
		}
	}
	
	for (auto _ : rows) {
		cout << _ << " ";
	}
	cout << "\n";
	
	for (auto _ : cols) {
		cout << _ << " ";
	}
	cout << "\n";

	return 0;
}