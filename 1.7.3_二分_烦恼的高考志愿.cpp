#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 3;
const int INF = 0x3f3f3f3f;

int stu[N];
int sch[N];

int m, n;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> m >> n;
	
	for (int i{}; i < m; ++i) cin >> sch[i];
	sort(sch, sch + m);
	
	int tar;
	ll sum{};
	for (int i{}; i < n; ++i) {
		cin >> tar;
		// cout << tar << endl;
		
		int l{}, r{m - 1}, _{INF};	
		while (l < r) {
			int mid{l + (r - l) / 2};
			if (sch[mid] >= tar) r = mid;
			else l = mid + 1;
		}
		if (sch[l] >= tar) _ = sch[l] - tar;
		l = 0, r = m - 1;
		while (l < r) {
			int mid{l + (r - l) / 2 + 1};
			if (sch[mid] <= tar) l = mid;
			else r = mid - 1;
		}
		if (sch[l] <= tar) _ = min(tar - sch[l], _);
		// cout << "_: " << _ << endl;
		sum += _;
	}
	cout << sum << "\n";

	return 0;
}