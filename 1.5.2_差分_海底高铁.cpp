#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 3;
const int M = 1e5 + 3;
int n, m;

int line[N]{0};
ll t[N]{0};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n >> m;
	
	for (int i{}; i < m; ++i) {
		cin >> line[i];
	}
 	
	for (int i{}; i < m - 1; ++i) {
		int l{line[i]}, r{line[i + 1]};
		if (l > r) {
			swap(l, r);
		}
		++t[l]; --t[r];
	}
	
	for (int i{1}; i < n; ++i) {
		t[i] += t[i - 1];
	}
	
	ll pA, pB;
	int a, b, c;
	ll ret{};
	for (int i{1}; i < n; ++i) {
		cin >> a >> b >> c;
		pA = t[i] * a;
		pB = c + t[i] * b;
		ret += min(pA, pB);
	}
	cout << ret << "\n";

	return 0;
}