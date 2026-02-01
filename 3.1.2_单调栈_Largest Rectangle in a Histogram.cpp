#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 7;
int n;
int h[N];
int w[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	while (cin >> n, n) {
		for (int i{1}; i <= n; ++i) cin >> h[i];

		stack<int> st1;
		stack<int> st2;
		for (int i{1}; i <= n; ++i) {
			while (st1.size() && h[st1.top()] >= h[i]) st1.pop();	
			if (st1.size()) w[i] = st1.top() + 1;
			else w[i] = 1;
			st1.emplace(i);
		}

		for (int i{n}; i >= 1; --i) {
			while (st2.size() && h[st2.top()] >= h[i]) st2.pop();
			if (st2.size()) w[i] = st2.top() - w[i];
			else w[i] = n + 1 - w[i];
			st2.emplace(i);
		}

		ll ret{};
		for (int i{1}; i <= n; ++i) {
			ret = max((ll)ret, (ll)w[i] * h[i]);
		}
		cout << ret << "\n";
	}

	return 0;
}