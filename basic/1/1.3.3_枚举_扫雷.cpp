#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int arr[2][10002]{0};
	for (int i{1}; i <= n; ++i) {
		cin >> arr[0][i];
	}
	
	int cnt{};
	for (int k{}; k < 2; ++k) {
		arr[1][1] = k;
		int flag{1};
		for (int i{2}; i < n + 2; ++i) {
			arr[1][i] = arr[0][i - 1] - arr[1][i - 2] - arr[1][i - 1];
			if (arr[1][i] != 1 && arr[1][i] != 0) {
				flag = 0;
				break;
			}
		}
		if (flag && arr[1][n + 1] == 0) {
			++cnt;
		}
	}
	
	cout << cnt <<"\n";
	return 0;
}