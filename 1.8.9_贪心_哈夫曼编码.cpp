#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 3;
using ll = long long;

ll a[N];
int n;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n;
	
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	int x;
	for (int i{}; i < n; i++) {
		cin >> x;
		pq.emplace(x);
	}
	
	ll ret{};
	while (pq.size() > 1) {
		ll a{pq.top()}; pq.pop();
		ll b{pq.top()}; pq.pop();
		ll c{a + b};
		pq.emplace(c);
		ret += c;
	}
	cout << ret << "\n";

	return 0;
}