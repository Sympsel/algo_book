#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
int n;
using ll =long long ;
ll a[N];
ll f[N];

int main() {
	cin >> n;
	for (int i{1}; i <= n; ++i) cin >> a[i];
	ll ret = -1e11;
	for (int i{1}; i <= n; ++i) {
		f[i] = max(a[i], f[i - 1] + a[i]);
		ret = max(ret, f[i]);
	}
	cout << ret << "\n";
	return 0;
}
