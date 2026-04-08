#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7;
const int INF = 2147483647;
using pii = pair<int, int>;
vector<pii> ed[N];

int n, m, s;
int dist[N];

void bellford() {
	for (int i{}; i <= n; ++i) dist[i] = INF;
		dist[s] = 0;

	bool flag{};
	for (int i{1}; i < n; ++i) {
		flag = false;
		for (int u{1}; u <= n; ++u) {
			if (dist[u] == INF) continue;
			for (auto& [v, w] : ed[u]) {
				if (dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					flag = true;
				}
			}
		}
		if (!flag) break;
	}
	for (int i{1}; i <= n; ++i) cout << dist[i] << " \n"[i == n];
}

int main() {
	cin >> n >> m >> s;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		ed[u].emplace_back(v, w);
	}
	bellford();
	return 0;
}
