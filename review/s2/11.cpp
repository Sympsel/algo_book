#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;
const int INF = 0x3f3f3f3f;

struct edge {
	int u, v, w;
	edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
	bool operator<(const edge& o) const {
		return w > o.w; 
	}
};
int uf[N];

inline int fd(int x) {
	return x == uf[x] ? x : uf[x] = fd(uf[x]);
}

inline void un(int x, int y) {
	int fx{fd(x)}, fy{fd(y)};
	if (fx != fy) {
		uf[fx] = fy;
	}
}

int n, m;
priority_queue<edge> q;

int main() {
	cin >> n >> m;
	for (int i{1}; i <= n; ++i) uf[i] = i;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		q.emplace(u, v, w);
	}

	int cnt{};
	int ret{};
	while (q.size()) {
		auto& [u, v, w]{q.top()};
		if (fd(u) != fd(v)) {
			++cnt;
			un(u, v);
			ret += w;
		}
		q.pop();
	}
	if (cnt == n - 1) cout << ret << "\n";
	else cout << "orz\n";
	return 0;
}
