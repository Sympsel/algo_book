#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int a[20]{0};
int b[20]{0};
int n;

int cnt1(int st) {
	int cnt{};
	while (st) {
		st &= (st - 1);
		++cnt;
	}
	return cnt;
}

// 变化只能从0到1，从1到0需要剪去
int isfit(int line, int push) {
	for (int i{}; i < n; ++i) {
		if (((line >> i) & 1) > ((push >> i) & 1)) {
			return 0;		
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int T;
	cin >> T;
	int t{1};
	while (t <= T) {
		cin >> n;
		
		// 从第一行开始读入，第零行全为 0
		for (int i{1}; i <= n; ++i) {
			char ch{};
			for (int j{}; j < n; ++j) {
				cin >> ch;
				if (ch == '1') {
					a[i + 1] |= 1 << j;
				}
			}
		}
		
		int ret{INF};
		for (int st{}; st < (1 << n); ++st) {
			memcpy(b, a, sizeof a);
			int push{st};
			int cnt{};
			for (int i{1}; i <= n; ++i) {
				if (!isfit(a[i], push)) {
					goto next;
				}
				cnt += cnt1(st);
				//  a
				// bcd
				//  e
				// e % 2 = (a + b + d) % 2
				// 异或其余三值的异或，异或不为0说明三个数的指定位和为奇数
				b[i] = (i > 1 ? b[i - 2] : 0) ^ (push << 1) ^ (push >> 1);
				// 消除溢出0
				b[i] &= (1 << n) - 1;
				// 下一行等于上一行的结果
				b[i + 1] = push;
			}
			ret = min(cnt, ret);
			
			next:;
		}
		
		cout << "case" << t++ << ": " << (ret == INF ? -1 : ret) << "\n";
	}

	return 0;
}