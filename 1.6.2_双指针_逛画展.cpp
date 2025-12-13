#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 1e6 + 7;

int a[N]{0};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n, m; cin >> n >> m;
	for (int i{}; i < n; ++i) {
		cin >> a[i];
	}
	
	unordered_map<int, int> s;
	int i{}, j{};
	int mb{}, ml{INF};
	while (j < n) {
		++s[a[j]];
		while (s.size() == m) {
			if (ml > j - i + 1) {
				mb = i;
				ml = j - i + 1;
			}
			--s[a[i]];
			if (s[a[i]] == 0) {
				s.erase(a[i]);
			}
			++i;
		}
		++j;
	}
	cout << mb + 1 << " " << mb + ml << "\n";

	return 0;
}