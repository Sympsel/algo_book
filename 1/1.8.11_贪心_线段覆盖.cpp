#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int n, bi, ei;

struct Pair {
	int b, e;
} p[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; ++i) cin >> p[i].b >> p[i].e;

	sort(p, p + n, [](const Pair& a, const Pair& b) {
		return a.b < b.b;
	});
	int ret{1};
	
	Pair prev{p[0]};
	for (int i{1}; i < n; ++i) {
		Pair curr{p[i]};
		if (curr.e < prev.e) {
			prev = curr;
		} else if (curr.b >= prev.e) {
			++ret;
			prev = curr;
		}
	}
	cout << ret << "\n";

	return 0;
}