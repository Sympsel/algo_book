#include <bits/stdc++.h>
using namespace std;

const int N = 33;
int n, m;
int f[N], g[N];


int main() {
	cin >> n >> m;
	f[1] = 1;
	int* arr = f, *brr = g;
	while (m--) {
		brr[1] = arr[n] + arr[2];
		for (int i{2}; i < n; ++i)
			brr[i] = arr[i - 1] + arr[i + 1];
		brr[n] = arr[n - 1] + arr[1];
		swap(arr, brr);
	}
		
	cout << arr[1] << "\n";
	return 0;
}
