#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 7;

int sz;
int a[N], b[N];
int disc[N];

using ll = long long;
int n;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	unordered_map<int, int> mp;
	for (int i{}; i < n; ++i) {
		cin >> a[i] >> b[i];
		disc[sz++] = a[i];
		disc[sz++] = b[i];
	}
	sort(disc, disc + sz);
	
	int id{};
	for (int i{}; i < sz; ++i) {
		int x{disc[i]};
		if (mp.count(x)) continue;
		mp[x] = id++;
	}
	
	int pre[N]{};
	for (int i{}; i < n; ++i) {
		++pre[mp[a[i]]];
		--pre[mp[b[i]]];
	}
	
	for (int i{}; i < 6; ++i) {
		cout << pre[i] << " ";
	}
	cout << "\n";
	
	for (int i{1}; i < n; ++i) {
		pre[i] += pre[i - 1];
	}
	
	// for (int i{}; i < 6; ++i) {
		// cout << disc[i] << " ";
	// }
	// cout << "\n";
	
	for (int i{}; i < 6; ++i) {
		cout << pre[i] << " ";
	}
	cout << "\n";
	
	ll ret{};
	int l{}, r{};
	for (int l{}; l < n; ++l) {
		if (!pre[l]) {
			r = l + 1;
			while (r < n && pre[r]) ++r;
			ret += disc[r - 1] - disc[l];
			l = r;
		}
	}
	
	// for (int i{}; i < id; ++i) {
		// if (pre[i] > 0) {
			// ret += (ll)(disc[i + 1] - disc[i]);
		// }
	// }
	cout << ret << "\n";

	return 0;
}