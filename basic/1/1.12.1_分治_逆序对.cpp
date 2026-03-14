#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;
using ll = long long;

ll ret;
int n;
int a[N];
int t[N];

ll mergeSort(int b, int e) {
	if (b >= e) {
		return 0;
	}
	
	int mid{((e - b) >> 1) + b};
	ll ret{mergeSort(b, mid) + mergeSort(mid + 1, e)};
	
	int i{b}, j{mid + 1}, k{b};
	while (i <= mid && j <= e) {
		if (a[i] <= a[j]) {
			t[k++] = a[i++];
		} else {
			ret += mid + 1 - i;
			t[k++] = a[j++];
		}
	}
	
	while (i <= mid) {
		t[k++] = a[i++];
	}
	
	while (j <= e) {
		t[k++] = a[j++];
	}
	
	memcpy(a + b, t + b, (e - b + 1) * sizeof(int));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n;
	for (int i{}; i < n; ++i) cin >> a[i];
	
	cout << mergeSort(0, n - 1) << "\n";

	return 0;
}