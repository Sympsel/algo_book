#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
const int INF = 0x3f3f3f3f;
int n, m;

int ed[N][N];
int f[N][N];
int dist[N];
bool st[N];

int prim() {
	for (int i{}; i <= n; ++i) {
		dist[i] = m;
	}
	dist[1] = 0;
	int ret{};
	for (int i{1}; i <= n; ++i) {
		int u{};
		for (int j{1}; j <= n; ++j)
			if (!st[j] && dist[j] < dist[u])
				u = j;
		st[u] = true;
		ret += dist[u];
		for (int v{1}; v <= n; ++v) {
			if (st[v] || ed[u][v] == 0) continue;
			dist[v] = min(dist[v], ed[u][v]);
		}
	}
	return ret + m;
}

int main() {
	cin >> m >> n;
	for (int i{1}; i <= n; ++i) {
		for (int j{1}; j <= n; ++j) {
			cin >> ed[i][j];
		}
	}

	int ret{prim()};
	cout << ret << "\n";
	return 0;
}