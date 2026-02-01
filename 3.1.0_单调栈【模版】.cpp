#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N];
int ret[N];

void test() {
	stack<int> st;
    for (int i{1}; i <= n; ++i) {
		while (st.size() && a[st.top()] <= a[i]) st.pop();
		if (st.size()) ret[i] = st.top();
		
		st.emplace(i);
	}
	for (int i{1}; i <= n; ++i) cout << ret[i] << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for (int i{1}; i <= n; ++i) cin >> a[i];
	
	test();

	return 0;
}
