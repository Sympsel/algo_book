#include <bits/stdc++.h>
using namespace std;

const int N = 12;
int ts[N], ds[N], ls[N];
bool a[N];
int n;

bool dfs(int sz, int e) {
	if (sz == n) {
		return true;
	}
	
	for (int i{}; i < n; ++i) {
		if (!a[i] && e <= ts[i] + ds[i]) {
			a[i] = true;
			if (dfs(sz + 1, max(e, ts[i]) + ls[i])) return true;
			a[i] = false;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int times; cin >> times;
	while (times--) {
		cin >> n;
		for (int i{}; i < n; ++i)
			cin >> ts[i] >> ds[i] >> ls[i];	
			
		if (dfs(0, 0)) cout << "YES\n";
		else cout << "NO\n";
		
		fill(a, a + n, false);
	}
	

	return 0;
}