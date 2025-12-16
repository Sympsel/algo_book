#include <bits/stdc++.h>
using namespace std;

const int N = 2 * (int)1e5;
using ll = long long;
int n, a[N];
const int INF = 1e6;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; ++i) cin >> a[i];
	ll ret{-INF}, sum{};
	
	for (int i{}; i < n; ++i) {
		sum += a[i];
		ret = max(ret, sum);
		if (sum < 0) {
			sum = 0;	
		}
	}
		
	cout << ret << "\n";
	return 0;
}