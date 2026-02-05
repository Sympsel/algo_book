#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

int tr[2][N * 31];
int a[N];
int idx;

void insert(const int& x) {
	int cur{};
	for (int i{30}; i >= 0; --i) {
		int id((x >> i) & 1);
		if (tr[id][cur] == 0)
			tr[id][cur] = ++idx;
		cur = tr[id][cur];
	}
}

int query(const int& x) {
	int cur{}, ret{};
	for (int i{30}; i >= 0; --i) {
		int id((x >> i) & 1);
		if (tr[id ^ 1][cur]) {
			ret |= (1 << i);
			cur = tr[id ^ 1][cur];
			
		} else {
			cur = tr[id][cur];
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n; cin >> n;
	for (int i{}; i < n; ++i) {
		cin >> a[i];
		insert(a[i]);
	}
	
	int mx{};
	for (int i{}; i < n; ++i) {
		mx = max(mx, query(a[i]));
	}
	cout << mx << "\n";

	return 0;
}