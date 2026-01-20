#include <bits/stdc++.h>
using namespace std;

int n;
int sz;
char str[1030];

void _print(int b, int e) {
	bool isB = true, isI = true;
	for (int i{b}; i <= e; ++i) {
		if (str[i] != '0') isB = false;
		if (str[i] != '1') isI = false;
		if (!isB && !isI) {
			cout << 'F';
			return;
		}
	}
	
	if (isB) {
		cout << 'B';
	} else {
		cout << 'I';
	}
}

void init() {
	cin >> n;
	// cin.get();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	sz = (1 << n);
	fill(str, str + 1030, '\0');
	cin.getline(str, 1030);
}

void dfs(int b, int e) {
	int mid{(b + e) / 2};
	if (b != e) {
		dfs(b, mid);
		dfs(mid + 1, e);
	}
	_print(b, e);
}

int main() {
	init(); 
	dfs(0, sz - 1);
	return 0;
}