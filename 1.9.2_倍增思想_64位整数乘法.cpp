#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a, b, m;

ll mul() {
	ll ret{};
	while (b) {
		if (b & 1) {
			ret = (ret + a) % m;
		}
		a = (a + a) % m;
		b >>= 1;
	}
	return ret;
}

// ll mul(ll a, ll b) {
	// if (b == 1) {
		// return a;
	// }
	// return (mul((a + a) % m, b / 2) + (b % 2 == 0 ? 0 : a)) % m;
// }

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> a >> b >> m;
	// cout << mul(a, b) << "\n";
	cout << mul() << "\n";

	return 0;
}