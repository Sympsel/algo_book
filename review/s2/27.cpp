#include <bits/stdc++.h>
using namespace std;

int nums, q;
const int N = 3e6 + 7;

int get_num(char ch) {
	if (ch >= 'A' && ch <= 'Z') return ch - 'A';
	if (ch >= 'a' && ch <= 'z') return ch - 'a' + 26;
	return ch - '0' + 52;
}

int tr[N][62];
int p[N], idx;

void insert(const string& s) {
	int cur{};
	++p[cur];
	for (auto ch : s) {
		int path{get_num(ch)};
		if (tr[cur][path] == 0) tr[cur][path] = ++idx;
		cur = tr[cur][path];
		++p[cur];
	}
}

void query(const string& s) {
	int cur{};
	for (auto ch : s) {
		int path{get_num(ch)};
		if (tr[cur][path] == 0) {
			cout << "0\n";
			return;
		}
		cur = tr[cur][path];
	}
	cout << p[cur] << "\n";
}

int main() {
	int t; cin >> t;
	while (t--) {
		for (int i{}; i <= idx; ++i)
			for (int j{}; j < 62; ++j)
				tr[i][j] = 0;
		for (int i{}; i <= idx; ++i)
			p[i] = 0;
		idx = 0;
		string s;
		cin >> nums >> q;
		while (nums--) {
			cin >> s;
			insert(s);
		}
		while (q--) {
			cin >> s;
			query(s);
		}
	}
	return 0;
}
