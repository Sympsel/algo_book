#include <bits/stdc++.h>
using namespace std;

const int N = 23;
int n, m;
int a[N];
bool prime(int x) {
	if (x <= 1) return false;
	for (int i{2}; i <= x / i; ++i)
		if (x % i == 0) return false;
	return true;
}

// dfs
// int cnt, sum;
// void dfs(int idx, int cur) {
// 	if (cur == m) {
// 		if (prime(sum)) {
// 			++cnt;
// 		}
// 		return;
// 	}
// 	if (idx > n) return;

// 	dfs(idx + 1, cur);
// 	sum += a[idx];
// 	dfs(idx + 1, cur + 1);
// 	sum -= a[idx];
// }

// 二进制枚举
// int cnt1(int x) {
// 	int cnt{};
// 	while (x) {
// 		x &= (x - 1);
// 		++cnt;
// 	}
// 	return cnt;
// }

// int cnt;
// void binenum() {
// 	for (int st{}; st < (1 << n); ++st) {
// 		if (cnt1(st) != m) continue;
// 		int tmp{st};

// 		int i{1};
// 		int sum{};
// 		for (int i{1}; i <= n; ++i) {
// 			if ((st >> (i - 1)) & 1) {
// 				sum += a[i];
// 			} 
// 		}
// 		if (prime(sum)) ++cnt;
// 	}
// }
2
int main() {
	cin >> n >> m;
	for (int i{1}; i <= n; ++i) cin >> a[i];
	// dfs(1, 0);
	binenum();
	cout << cnt << "\n"; 
	return 0;
}
