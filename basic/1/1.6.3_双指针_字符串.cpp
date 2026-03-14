#include <bits/stdc++.h>
using namespace std;

int rf[26]{0};

string str;

void solve() {
	int cnt{};
	int i{}, j{}, ml{0x3f3f3f3f};
	while (j < str.size()) {
		char lc{str[i]}, rc{str[j]};
		++rf[rc - 'a'];
		if (rf[rc - 'a'] == 1) {
			++cnt;
		}
		
		while (cnt == 26) {
			ml = min(j + 1 - i, ml);
			--rf[lc - 'a'];
			if (rf[lc - 'a'] == 0) {
				--cnt;
			}
			
			lc = str[++i];
		}
		
		++j;
	}
	cout << ml << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> str;
	solve();

	return 0;
}