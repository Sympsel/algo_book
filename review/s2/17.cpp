#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int N = 1e4 + 7;
const int INF = 2147483647;
int n, m, s;

vector<pii> ed[N];
int dist[N];
bool st[N]; // inqueued

void spfa() {
	for (int i{}; i <= n; ++i) dist[i] = INF;
	dist[s] = 0;
	queue<int> q;
	q.emplace(s);
	st[s] = true;

	while (q.size()) {
		auto u{q.front()}; q.pop();
		st[u] = false;
		for (auto [v, w] : ed[u]) {
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				if (!st[v]) {
					q.emplace(v);
					st[v] = true;
				}
			}
		}
	}
	for (int i{1}; i <= n; ++i) cout << dist[i] << " \n"[i == n];
}

int main() {
	cin >> n >> m >> s;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		ed[u].emplace_back(v,w );
	}
	spfa();

	return 0;
}
