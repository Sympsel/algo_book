#include <bits/stdc++.h>
using namespace std;

const int N = 23;

int n, k;
int a[N];
vector<int> path;
int cnt;

bool isPrime(int val) {
	if (val <= 1) return false;
	for (int i{2}; i <= val / i; ++i) {
		if (val % i == 0) return false;
	}
	return true;
}

void dfs(int b) {
	if (path.size() == k + 1) {
		if (isPrime(path.back())) {
			++cnt;
		}
		return;
	}
	
	for (int i{b + 1}; i <= n; ++i) {
		path.emplace_back(a[i] + path.back());
		dfs(i);
		path.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i{1}; i <= n; ++i) cin >> a[i];
	path.emplace_back(0);
	dfs(0);
	cout << cnt << "\n";
	return 0;
}
