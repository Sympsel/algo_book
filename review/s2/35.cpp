#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;
int a[N];
int f[N];
int n;

int main() {
	cin >> n;
	for (int i{1}; i <= n; ++i) cin >> a[i];
	int ret{1};
	for (int i{1}; i <= n; ++i) {
		f[i] = 1;
		for (int j{1}; j < i; ++j) {
			if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
		}
		ret = max(ret, f[i]);
	}
	cout << ret << "\n";
	return 0;
}