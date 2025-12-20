#include <bits/stdc++.h>
using namespace std;

using  ll = long long;
int n;
const int N = 5e4 + 3;
struct Node {
	ll w, s;
} a[N];

ll f[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; ++i) cin >> a[i].w >> a[i].s;
	sort(a, a + n, [](const Node& x, const Node& y) {
		return max(-x.s, x.w - y.s) < max(y.w - x.s, - y.s);
	});
	
	
	ll ret(-1e19), sumWeight{};
	for (int i{}; i < n; i++) {
		ret = max(ret, sumWeight - a[i].s);
		sumWeight += a[i].w;
	}

	cout << ret << "\n";

	return 0;
}