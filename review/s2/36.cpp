#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N];
int f[N];
int len;
int n;

int main() {
	cin >> n;
	for (int i{1}; i <= n; ++i) cin >> a[i];
	for (int i{1}; i <= n; ++i) {
		if (len == 0 || a[i] > f[len]) {
			f[++len] = a[i];
		} else {
			int l{1}, r{len};
			while (l < r) {
				int mid{(l + r) / 2};
				if (f[mid] > a[i]) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			f[l] = a[i];
		}
	}
	cout << len << "\n";
	return 0;
}