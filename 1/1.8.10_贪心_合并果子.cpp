#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	int x;
	for (int i{}; i < n; i++) {
		cin >> x;
		pq.emplace(x);
	}
	
	int ret{};
	while (pq.size() > 1) {
		int x{pq.top()}; pq.pop();
		int y{pq.top()}; pq.pop();
		int sum{x + y};
		ret += sum;
		pq.emplace(sum);
	}
	cout << ret << "\n";

	return 0;
}