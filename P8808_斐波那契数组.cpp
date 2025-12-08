#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
const int M = 1e6;
int n;
int ret;
int a[N]{0};
int fib[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	cin >> n;
	for (int i{}; i < n; ++i) {
		cin >> a[i];	
	}
	
	fib[0] = fib[1] = 1;
	 // 初始化为n，表示所有位置都有效
	int m{n};
	for (int i{2}; i < n; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] > M) {
			// 找到第一个大于所有a[i]的值，索引大于m的所有a的值都需要改变
			m = i - 1;
			break;
		}
	}
	
	unordered_map<int, int> tab;
	// 如果存在值域越界，就仅遍历到不越界的位置，其余位置均需要改变
	for (int i{}; i < min(n, m + 1); ++i) {
		if (a[i] % fib[i] == 0) {
			++tab[a[i] / fib[i]];
		}
	}
	int Max{};
	for (auto& [_, x] : tab) { 
		if (Max < x) {
			Max = x;
		}
	}
	cout << n - Max << "\n";
	return 0;
}