#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;
int n;

struct Node {
	int t, d;
} a[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; i++) cin >> a[i].t >> a[i].d;

	sort(a, a + n, [](const Node& x, const Node& y) {
		return x.t * y.d < y.t * x.d;
	});
	
	ll ret{};
	int t{};
	for (int i{}; i < n; i++) {
		ret += t * a[i].d;
		t += 2 * a[i].t;
	}
	
	cout << ret << "\n";
	return 0;
}