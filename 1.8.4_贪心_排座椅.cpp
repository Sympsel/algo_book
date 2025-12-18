#include <bits/stdc++.h>
using namespace std;

int m, n, k, l, d;
const int N = 1e3 + 5;

struct Node {
	int idx;
	int cnt;	
}rows[N], cols[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> m >> n >> k >> l >> d;
	int x1, y1, x2, y2;
	for (int i{}; i < m; ++i) rows[i].idx = i;
	for (int i{}; i < n; ++i) cols[i].idx = i;
	
	while (d--) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) {
			cols[min(y1, y2)].cnt++;
		} else {
			rows[min(x1, x2)].cnt++;
		}
	}
	
	function<bool(const Node& a, const Node& b)> f1 = [](const Node& a, const Node& b) {
		return a.cnt > b.cnt;
	};
	
	function<bool(const Node& a, const Node& b)> f2 = [](const Node& a, const Node& b) {
		return a.idx < b.idx;
	};
	
	sort(rows, rows + m, f1);
	sort(cols, cols + n, f1);
	
	sort(rows, rows + k, f2);
	sort(cols, cols + l, f2);
	
	for (int i{}; i < k; ++i) {
		cout << rows[i].idx << " ";
	}
	cout << "\n";
	for (int i{}; i < l; ++i) {
		cout << cols[i].idx << " ";
	}
	cout << "\n";

	return 0;
}