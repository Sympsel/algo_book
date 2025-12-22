#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7;

struct Sec {
	double l, r;	
} S[N];
int n;
ll d;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	ll cs{1};
	while (cin >> n >> d, n && d) {
		ll x, y, ret{1};
		bool invalid{false};
		for (int i{}; i < n; ++i) {
			cin >> x >> y;
			if (y > d) {
				ret = -1;
				invalid = true;
				break;
			}
			double dx = sqrt(d * d - y * y);
			S[i].l = x - dx, S[i].r = x + dx;
		}
		
		if (!invalid) {
			sort(S, S + n, [](const Sec& a, const Sec& b) {
				return a.l < b.l;
			});
			
			Sec prev{S[0]};
			for (int i{1}; i < n; ++i) {
				const Sec& curr{S[i]};
				if (curr.l > prev.r) {
					++ret;
					prev = curr;
				} else {
					prev.l = curr.l;
					prev.r = min(prev.r, curr.r);
				}
			}
		}
		
		cout << "Case " << cs++ << ": " << ret << "\n";
	}

	return 0;
}