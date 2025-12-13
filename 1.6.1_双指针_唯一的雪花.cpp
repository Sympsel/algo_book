#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int a[N]{0};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i{}; i < n; ++i) {
			cin >> a[i];
		}
		
		int ms{};
		int i{}, j{};
		unordered_set<int> s;
		while (j < n) {
			while (s.count(a[j])) {
				ms = max(ms, (int)s.size());
				s.erase(a[i++]);
			}
			s.emplace(a[j]);
			
			++j;
		}
		cout << max(ms, (int)s.size()) << "\n";
	}

	return 0;
}