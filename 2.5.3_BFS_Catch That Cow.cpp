#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
const int MIN = 1;

bool v[MAX + 3];

int t, x, y;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> t;
	while (t--) {
		cin >> x >> y;
		int ret{};
		queue<int> q;
		q.emplace(x);
		v[x] = true;
		bool solved{false};
		
		while (q.size()) {
			if (solved) break;
			int sz(q.size());
			++ret;
			while (sz--) {
				int currX{q.front()}; q.pop();
				int newX{currX * 2};
				for (int i{}; i < 3; ++i) {
					if (i == 1) {
						newX = currX + 1;
					} else if (i == 2) {
						newX = currX - 1;
					}
					
					if (newX <= MAX && newX >= MIN && !v[newX]) {
						if (newX == y) {
							solved = true;
							break;
						}
						
						q.emplace(newX);
						v[newX] = true;
					}
					newX = currX;
				}
			}
		}
		cout << ret << "\n";
		memset(v, false, sizeof v);
	}

	return 0;
}