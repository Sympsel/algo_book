#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
const int INF = 0x3f3f3f3f;

int a[N];
int n, k;

long long calc(int len) {
	long long cnt{};
	for (int i{n - 1}; i >= 0; --i) {
		cnt += a[i] / len;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> k;
	
	for (int i{}; i < n; ++i) cin >> a[i];
	sort(a, a + n);

    if (calc(1) < k) {
        cout << 0 << "\n";
        return 0;
    }

	int l{1}, r{a[n - 1]};
	while (l < r) {
		int mid{l + (r - l) / 2 + 1};
		if (calc(mid) >= k) l = mid;
		else r = mid - 1;
	}
	
	cout << l << "\n";

	return 0;
}