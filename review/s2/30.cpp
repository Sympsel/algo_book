#include <bits/stdc++.h>
using namespace std;

const int N = 63;
using ll = long long;
ll f[N];
int n;

int main() {
	cin >> n;
	f[0] = 1; f[1] = 1; f[2] = 2;
	for (int i{3}; i <= n; ++i) {
		f[i] = f[i - 1] + f[i - 2] + f[i - 3];
	}
	cout << f[n] << "\n";
	return 0;
}