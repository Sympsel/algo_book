#include <bits/stdc++.h>
using namespace std;

char a[14][5];
char b[14];

map<char, int> mp;

void init() {
	fill(b, b + 14, 4);
	for (int i{2}; i < 10; ++i) mp['0' + i] = i;
	mp['A'] = 1; mp['0'] = 10; mp['J'] = 11;
	mp['Q'] = 12; mp['K'] = 13;
	
	for (int i{1}; i <= 13; ++i)
		for (int j{1}; j <= 4; ++j)
			cin >> a[i][j];
}

void cycle(int col) {
	if (b[col] == 0) return;
	char ch{a[col][b[col]--]};
	if (ch == 'K') return;
	cycle(mp[ch]);
}

void life(int id) {
	if (id == 5) return;
	char ch{a[13][id]};
	if (ch == 'K') {
		life(id + 1);
		return;
	}
	cycle(mp[ch]);
	
	life(id + 1);
}

int getRet() {
	int ret{};
	for (int i{1}; i < 13; ++i) {
		if (!b[i]) ++ret;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	init();
	
	life(1);
	
	cout << getRet() << "\n";

	return 0;
}