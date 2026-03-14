#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 4;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i{1}; i <= n; ++i)
		cin >> a[i];	

	deque<int> q;
	for (int i{1}; i <= n; ++i) {
		while (q.size() && a[q.back()] >= a[i]) q.pop_back();
		q.emplace_back(i);
		if (q.back() - q.front() == m) q.pop_front();
		if (i >= m) cout << a[q.front()] << "\n";
	}

	return 0;
}