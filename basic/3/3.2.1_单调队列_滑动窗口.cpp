#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int n, k;
int a[N];
int maxs[N];
int mins[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i{1}; i <= n; ++i) 
		cin >> a[i];

	deque<int> q1;

	deque<int> q2;
	for (int i{1}; i <= n; ++i) {
		while (q2.size() && a[q2.back()] >= a[i]) q2.pop_back();
		q2.emplace_back(i);
		if (q2.back() - q2.front() == k) q2.pop_front();
		if (i >= k)
			cout << a[q2.front()] << " ";
	}
	cout << "\n";
	for (int i{1}; i <= n; ++i) {
		while (q1.size() && a[q1.back()] <= a[i]) q1.pop_back();
		q1.emplace_back(i);
		if (q1.back() - q1.front() == k) q1.pop_front();
		if (i >= k)
			cout << a[q1.front()] << " ";
	}
	cout << "\n";
	return 0;
}