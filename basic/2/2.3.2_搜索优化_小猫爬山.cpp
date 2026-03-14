#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n, limit;
int cat[N];
vector<int> car;
int ret;

void dfs(int idx) {
	if (car.size() >= ret) return;
	if (idx == n) {
		ret = car.size();
		return;
	}
	
	for (int i{}; i < car.size(); ++i) {
		if (car[i] + cat[idx] > limit) continue;
		car[i] += cat[idx];
		dfs(idx + 1);
		car[i] -= cat[idx];
	}
	
	car.emplace_back(cat[idx]);
	dfs(idx + 1);
	car.pop_back();
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> limit;
	
	for (int i{}; i < n; ++i) cin >> cat[i];
	sort(cat, cat + n, greater<int>());
	ret = n;
	dfs(0);
	cout << ret << "\n";

	return 0;
}