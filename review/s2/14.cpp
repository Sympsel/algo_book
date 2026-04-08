#include <bits/stdc++.h>
using namespace std;

const int N = 510;
bool st[N];
vector<int> ed[N];
int in[N];
int t; // 总监控数

void topo() {
	int cnt{};
	queue<int> q;
	bool flag{true};
	for (int i{}; i <= 500; ++i) {
		if (st[i] && in[i] == 0) {
			q.emplace(i);
			flag = false;
		}
	}
	if (flag) {
		cout << t << "\n";
		return;
	}
	while (q.size()) {
		auto u{q.front()}; q.pop();
		++cnt;
		for (auto& v : ed[u]) {
			--in[v];
			if (in[v] == 0 && st[v]) {
				q.emplace(v);
			}
		}
	}
	if (cnt == t) cout << "YES\n";
	else cout << (t - cnt) << "\n";
}

int main() {
	cin >> t;
	for (int i{1}; i <= t; ++i) {
		int u, n;
		cin >> u >> n;
		st[u] = true;
		while (n--) {
			int v; cin >> v;
			ed[u].emplace_back(v);
			++in[v];
		}
	}
	topo();
}
