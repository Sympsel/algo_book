#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int a[N];
int n;
// N * 32 每一位都可能是一个节点
int tr[2][N * 32];
int idx;

void insert(int num) {
	int cur{};
	for (int i{30}; i >= 0; --i) {
		int path = (num >> i) & 1;
		if (tr[path][cur] == 0) tr[path][cur] = ++idx;
		cur = tr[path][cur];
	}
}

int fd(int num) {
	int cur{};
	int ret{};
	for (int i{30}; i >= 0; --i) {
		int path = (num >> i) & 1;
		// 节点非0就表示存在
		if (tr[path ^ 1][cur] != 0) {
			ret |= (1 << i);
			cur = tr[path ^ 1][cur];
		} else {
			cur = tr[path][cur];
		}
	}
	return ret; 
}

int main() {
	cin >> n;
	for (int i{1}; i <= n; ++i) {
		cin >> a[i];
		insert(a[i]);
	}

	int ret{};
	for (int i{1}; i <= n; ++i) {
		ret = max(ret, fd(a[i]));
	}
	cout << ret << "\n";

	return 0;
}