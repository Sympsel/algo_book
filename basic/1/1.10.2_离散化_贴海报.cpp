#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 3;
const int M = 1e3 + 3;

int n, m;
int a[M], b[M];
unordered_map<int, int> mp;

int dist[M * 4], sz;
int w[M * 4];
bool st[M * 4];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i{}; i < m; ++i) {
		cin >> a[i] >> b[i];
		dist[sz++] = a[i], dist[sz++] = b[i];
		dist[sz++] = a[i] + 1, dist[sz++] = b[i] + 1;
	}
	
	sort(dist, dist + sz);
	
	int id{};
	for (int i{}; i < sz; ++i) {
		int x{dist[i]};
		if (mp.count(x)) continue;
		mp[x] = id++;
	}
	
	for (int i{}; i < m; ++i) {
		int l{mp[a[i]]}, r{mp[b[i]]};
		for (int j{l}; j <= r; ++j)
			w[j] = i + 1;
	}
	
	int ret{};
	
	for (int i{}; i < id; ++i) {
		int x{w[i]};
		if (!x || st[x]) continue;
		st[x] = true;
		++ret;
	}
	
	cout << ret << "\n";

	return 0;
}