#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;

int n;
int h[N], v[N];
int ret[N];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for (int i{1}; i <= n; ++i) cin >> h[i] >> v[i];

	stack<int> st;
	for (int i{1}; i <= n; ++i) {
		while (st.size() && h[st.top()] <= h[i]) st.pop();
		if (st.size()) ret[st.top()] += v[i];
		st.emplace(i);
	}

	stack<int> st2;
	for (int i{n}; i >= 1; --i) {
		while (st2.size() && h[st2.top()] <= h[i]) st2.pop();
		if (st2.size()) ret[st2.top()] += v[i];
		st2.emplace(i);
	}
	int res{};
	for (int i{1}; i <= n; ++i) {
		res = max(res, ret[i]);
	}
	cout << res << "\n";

	return 0;
}