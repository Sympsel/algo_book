#include <bits/stdc++.h>
using namespace std;

const int N = 203;
int n, m;
string strs[N];

int matchStr(const string& str1, const string& str2) {
    int ml{};
    for (int i{}; i < str1.size(); ++i) {
        for (int j{}; j < str2.size(); ++j) {
            int l{};
			
            for (int k{}; k < min((int)str1.size(), (int)str2.size()) - i; ++k) {
                if (str1[i + k] == str2[j + k]) {
                    ++l;
                    if (l > ml) {
                        ml = l;
                    }
                } else {
                    break;
                }
            }
        }
    }
    return ml;
}

struct Edge {
	int u, v, w;
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
	
	bool operator<(const Edge& o) const {
		return w > o.w;
	}
};

class DSU {
	public:
	DSU(int n) {
		p.resize(n);
		r.resize(n, 0);
		for (int i{}; i < n; ++i) {
			p[i] = i;
		}
	}
	
	int find(int x) {
		if (p[x] != x) {
			p[x] = find(p[x]);
		}
		return p[x];
	}
	
	bool unite(int x, int y) {
		int rx{find(x)};
		int ry{find(y)};
		if (rx == ry) {
			return false;
		}
		
		if (r[rx] < r[ry]) {
			p[rx] = ry;
		} else if (r[rx] > r[ry]) {
			p[ry] = rx;
		} else {
			p[ry] = rx;
			++r[rx];
		}
		return true;
	}
	
	private:
	vector<int> p, r;
};

void solve() {
	vector<Edge> edges;
	for (int i{}; i < n; ++i) {
		for (int j{i + 1}; j < n; ++j) {
			int w{matchStr(strs[i], strs[j])};
			if (w > m) {
				w = m;
			}
			edges.emplace_back(i, j, w);
		}
	}
	
	sort(edges.begin(), edges.end());
	
	DSU dsu(n);
	long long ret{};
	int usedEdge{};
	for (const auto& edge :edges) {
		if (dsu.unite(edge.u, edge.v)) {
			ret += edge.w;
			++usedEdge;
			if (usedEdge == n - 1) {
				break;
			}
		}
	}
	cout << ret << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> m;
	string s;
	for (int i{}; i < n; ++i) {
		cin >> s;
		s += s;
		strs[i] = s;
	}
	
	solve();

	return 0;
}