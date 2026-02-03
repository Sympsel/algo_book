#include <bits/stdc++.h>
using namespace std;

using L = long;
const int N = 1e5 + 7;
int t;
int n;
L a[N], b[N];
bool e[N];
int f[N * 2];
int k;
int uf[N * 2];

int fd(int x) {
	return uf[x] == x ? x : uf[x] = fd(uf[x]);
}

void un(int x, int y) {
	if (x != y) uf[fd(x)] = fd(y);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> t;
	while (t--) {
		unordered_map<L, int> mp;
		k = 0;
		cin >> n;
		for (int i{}; i < n; ++i) {
			cin >> a[i] >> b[i] >> e[i];
			f[k++] = a[i];
			f[k++] = b[i];
		}
		sort(f, f + k);
		k = unique(f, f + k) - f;

		for (int i{}; i < k; ++i) {
			mp[f[i]] = i;
			uf[i] = i;
		}

		for (int i{}; i < n; ++i) {
			if (e[i]) {
				un(mp[a[i]], mp[b[i]]);
			}
		}
		bool flag{true};
		for (int i{}; i < n; ++i) {
			if (!e[i]) {
				if (fd(mp[a[i]]) == fd(mp[b[i]])) {
					flag = false;
					break;
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
} 