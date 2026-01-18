#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e4 + 3;

int a[N], b[N];
int sz;
int dist[N * 2];
int n;
unordered_map<int, int> mp;
int f[N * 2];

int main() {
	cin >> n;
	for (int i{}; i < n; ++i) {
		cin >> a[i] >> b[i];
		dist[sz++] = a[i], dist[sz++] = b[i];
	}
	
	sort(dist, dist + sz);
	sz = unique(dist, dist + sz) - dist;
	
	int id{};
	for (int i{}; i < sz; ++i) {
		mp[dist[i]] = id++; 
	}
	
	for (int i{}; i < n; ++i) {
		int l{mp[a[i]]}, r = {mp[b[i]]};
		f[l]++, f[r]--;
	}
	
	for (int i{1}; i < sz; ++i) {
		f[i] += f[i - 1];
	}
	
	ll ret{};
	for (int i{}; i < sz; ++i) {
		if (f[i] == 0) continue;
		int j = i;
		while (j < sz && f[j]) {
			++j;
		}
		ret += (ll)dist[j] - (ll)dist[i];
		i = j;
	}
	
	cout << ret << "\n";
	
	return 0;
}