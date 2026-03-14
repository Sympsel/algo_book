#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 3;
int tr[N][26];
int e[N];
int idx;
string s;

void insert() {
	cin >> s;
	int cur{};
	for (auto& ch : s) {
		int id(ch - 'a');
		if (tr[cur][id] == 0)
			tr[cur][id] = ++idx;
		cur = tr[cur][id];
	}
	++e[cur];
}

void build() {
	int t; cin >> t;
	while (t--) {
		insert();
	}
}

void query() {
	cin >> s;
	int cur{};
	for (auto& ch : s) {
		int id(ch - 'a');
		if (tr[cur][id] == 0) {
			cout << "WRONG\n";
			return;
		}
		cur = tr[cur][id];
	}
	if (e[cur] > 0) {
		cout << "OK\n";
		e[cur] = -1;
	} else if (e[cur] == -1) {
		cout << "REPEAT\n";
	} else {
		cout << "WRONG\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	build();
	int t; cin >> t;
	while (t--) {
		query();
	}

	return 0;
}