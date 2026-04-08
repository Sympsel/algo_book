#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
const int INF = 2147483647;
using pii = pair<int, int>;
int n, m;
vector<pii> ed1[N];
vector<pii> ed2[N];
int dist1[N];
int dist2[N];
int st1[N];
int st2[N];

void dijkstra(vector<pii>* ed, int* dist, int* st) {
	for (int i{}; i <= n; ++i) dist[i] = INF;
	dist[1] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.emplace(0, 1);

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
}

int main() {
	cin >> n >> m;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		ed1[u].emplace_back(v, w);
		ed2[v].emplace_back(u, w);
	}
	dijkstra(ed1, dist1, st1);
	dijkstra(ed2, dist2, st2);
	int ret{};
	for (int i{1}; i <= n; ++i) {
		ret += dist1[i];
		ret += dist2[i];
	}
	cout << ret << "\n";
	return 0; 
}
