#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

int xs[N]{}, fs[N]{}, n;
int hs[N], e[N * 2]{}, ne[N * 2]{}, ind;
int son[N * 31][2], cnt[N * 31], idx;

void add(int x, int y) {
	e[ind] = y, ne[ind] = hs[x], hs[x] = ind++;
}

void modify(int x, int d) {
	int p{};
	cnt[p] += d;
	for (int i{30}; i >= 0; --i) {
		int b{(x >> i) & 1};
		if (d > 0 && son[p][b] == 0) {
			son[p][b] = ++idx;
		}
		p = son[p][b];
		cnt[p] += d;
	}
}

int query(int x) {
	int p{}, res{};
	for (int i{30}; i >= 0; --i) {
		int b{(x >> i) & 1};
		if (son[p][b ^ 1] && cnt[son[p][b ^ 1]] > 0) {
			res |= (1 << i);
			p = son[p][b ^ 1];
		} else {
			p = son[p][b];
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	
	memset(hs, -1, sizeof hs);
	cin >> n;
	for (int i{}; i < n; ++i) {
		cin >> xs[i];
	}
	
	for (int i{}; i < n; ++i) {
		cin >> fs[i];
		if (fs[i] != -1) {
			add(i, fs[i]);
			add(fs[i], i);
		}
 	}
 	
 	for (int i{}; i < n; ++i) {
 		modify(xs[i], 1);
 	}
 	
 	int ans{};
 	for (int i{}; i < n; ++i) {
 		modify(xs[i], -1);
 		for (int p{hs[i]}; p != -1; p = ne[p]) {
 			modify(xs[e[p]], -1);
 		}
 		int t{query(xs[i])};
 		ans = max(ans, t);
 		modify(xs[i], 1);
 		for (int p{hs[i]}; p != -1; p = ne[p]) {
 			modify(xs[e[p]], 1);
 		}
 	}
 	cout << ans << "\n";
	return 0;
}