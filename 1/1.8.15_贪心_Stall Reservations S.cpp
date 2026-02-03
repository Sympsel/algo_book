#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 = 7;

struct Cow {
	int id, a, b, c;
}c[N];

int n;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; ++i) {
		cin >> c[i].a >> c[i].b;
		c[i].id = i;
	}
	sort(c, c + n, [](const Cow& a, const Cow& b) {
		return a.a < b.a;
	});
	
	int ans{};
	
	
	
	cout << ans << "\n";	

	return 0;
}