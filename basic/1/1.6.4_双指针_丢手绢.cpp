#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
int n;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n;
	int sum{};
	for (int i{}; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
		
	// 5
	// 4 6 2 1 8 4 6 2 1 8
	int i{}, j{}, k{}, ml{};
	while (j < n) {
		k += a[j];
		while (2 * k > sum) {
			ml = max(ml, sum - k);
			k -= a[i++];
		}
		++j;
		ml = max(ml, k);
	}
	
	cout << ml << "\n";
	return 0;
}