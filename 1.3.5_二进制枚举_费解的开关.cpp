#include <bits/stdc++.h>
using namespace std;

const int n = 5;
const int INF = 0x3f3f3f3f;
#define N 10
int a[N]{0}, b[N]{0};

int cnt1(int x) {
	int cnt{};
	while (x) {
		++cnt;
		x &= (x - 1);
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	
	int times;
	cin >> times;
	while (times--) {
		// 清空上次遗留数据
		memset(a, 0, sizeof a);
		// 读入数据
		for (int i{}; i < n; ++i) {
			char ch;
			for (int j{}; j < n; ++j) {
				cin >> ch;
				if (ch == '0') {
					a[i] |= (1 << j);
				}
			}
		}
		
		int ret{INF};
		// 按位枚举所有第一行的操作状态
		for (int st{}; st < (1 << n); ++st) {
			// 拷贝初始情况下第一行的情况
			memcpy(b, a, sizeof a);
			int push{st};
			int cnt{};
			for (int i{}; i < n; ++i) {
				cnt += cnt1(push);
				if (cnt > 6) {
					// 跳出内层循环然后continue
					goto next;
				}
				b[i] = b[i] ^ push ^ (push << 1) ^ (push >> 1);
				b[i] &= (1 << n) - 1;
				b[i + 1] ^= push;
				// 下一层状态由上层决定
				push = b[i];
			}
			if ( b[n - 1] == 0) {
				ret = min(ret, cnt);
			}
			next:
		}
		if (ret > 6) {
			cout << -1 << "\n";
		} else {
			cout << ret << "\n";
		}
	}
	
	
	return 0;
}