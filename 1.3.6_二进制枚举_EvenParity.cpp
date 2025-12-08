#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int a[20]{0};
int b[20]{0};
int n;

int cntDiff(int lineA, int lineB) {
    int ret{};
    for (int i{}; i < n; ++i) {
        int x{lineA & 1};
        int y{lineB & 1};
        if (x > y) {
            return -1;
        }
        if (x != y) {
            ++ret;
        }
        lineA >>= 1;
        lineB >>= 1;
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	// 10010
	// 11110
	
	
	int T;
	cin >> T;
	int t{1};
	while (t <= T) {
		memset(a, 0, sizeof a);
		cin >> n;
		// 读入数据
		for (int i{1}; i <= n; ++i) {
			char ch;
			for (int j{}; j < n; ++j) {
				cin >> ch;
				if (ch == '1') {
			 		a[i] |= (1 << j);
			 	}
			}
		}
		int ret{INF};
		
		for (int st{}; st < (1 << n); ++st) {
			memcpy(b, a, sizeof a);
			int cnt{};
			
			for (int i{1}; i <= n; ++i) {
				if (i == 1) {
					b[i] = st;
				} else {
					b[i] = (b[i - 1] << 1) ^ (b[i - 1] >> 1) ^ b[i - 2];
					b[i] &= (1 << n) - 1;
				}
				
				int _{cntDiff(a[i], b[i])};
				if (_ == -1) {
					goto next;
				}
				cnt += _;
			}
			ret = min(ret, cnt);
			next:;
		}
		
		cout << "Case " << t << ": " << (ret == INF ? -1 : ret) << endl;
		++t;
	}

	return 0;
}