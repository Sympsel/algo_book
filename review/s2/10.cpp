#include <bits/stdc++.h>
using namespace std;

const int N = 5007;
const int INF = 0x3f3f3f3f;
int n, m;
using pii = pair<int, int>;
vector<pii> ed[N];
int dist[N];
bool st[N];

int prim() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	int ret{};
	for (int i{1}; i <= n; ++i) {
		int u{};
		for (int j{1}; j <= n; ++j) {
			if (!st[j] && dist[j] < dist[u]) {
				u = j;
			}
		}

		if (u == 0) return INF;
		st[u] = true;
		ret += dist[u];
		for (auto& [v, w] : ed[u]) {
			dist[v] = min(dist[v], w);
		}
	}
	return ret;	
}

int main() {
	cin >> n >> m;
	while (m--) {
		int u, v, w; 
		cin >> u >> v >> w;
		ed[u].emplace_back(v, w);
		ed[v].emplace_back(u, w);
	}
	int ret{prim()};
	if (ret == INF) cout << "orz\n";
	else cout << ret << "\n";

	return 0;
}
