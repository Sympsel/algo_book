#include <iostream>
using namespace std;

using ll = long long;

ll a, b, m;

// ll mypow(ll a, ll b) {
	// if (b == 0) return 1;
	// ll halfpow = mypow(a, b / 2) % m;
	// return (b % 2 == 0 ? 1 : a) * (halfpow * halfpow % m) % m;
// }

ll mypow(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b & 1) ret = ret * a % m;
		a = a * a % m;
		b >>= 1;
		}
	return ret;
}

int main() {
	cin >> a >> b >> m;
	ll ret = mypow(a, b);
	cout << a << "^" << b << " mod " << m << "=" << ret << "\n";
	return 0;
}
