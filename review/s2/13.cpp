#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int in[N];
// bool g[N][N];
vector<int> ed[N];
int n;

void topo() {
	queue<int> q;
	for (int i{1}; i <= n; ++i) {
		if (in[i] == 0) {
			q.emplace(i);
		}
	}

	while (q.size()) {
		auto u{q.front()}; q.pop();
		cout << u << " ";
		for (auto& v : ed[u]) {
			--in[v];
			if (in[v] == 0) q.emplace(v);
		}
	}
}

int main() {
	cin >> n;
	for (int u{1}; u <= n; ++u) {
		int v{};
		while (cin >> v, v) {
			ed[u].emplace_back(v);
			++in[v];
		}
	}
	topo();

	return 0;
}
