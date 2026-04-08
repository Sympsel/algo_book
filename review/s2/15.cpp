#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
const int N = 1e4 + 7;
const int INF = 2147483647;
using pii = pair<int, int>;
vector<pii> ed[N];
int dist[N];
bool st[N];
int n, m, s;

void dijkstra() {
	for (int i{}; i <= n; ++i) dist[i] = INF;
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.emplace(0, s);
	while (q.size()) {
		auto [_, u]{q.top()}; q.pop();
		if (st[u]) continue;
		st[u] = true;

		for (auto& [v, w] : ed[u]) {
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				q.emplace(dist[v], v);
			}
		}
	}

	for (int i{1}; i <= n; ++i) cout << dist[i] << " \n"[i == n];
}

int main() {
	cin >> n >> m>> s;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		ed[u].emplace_back(v, w);
	}
	dijkstra();
	return 0;
}
