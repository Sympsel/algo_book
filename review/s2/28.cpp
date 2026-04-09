#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 7;

int tr[N][26];
int e[N];
int idx;
int n, q;

void insert(string& s) {
	int cur{};
	for (char ch : s) {
		int path = ch - 'a';
		if (tr[cur][path] == 0) tr[cur][path] = ++idx;
		cur = tr[cur][path];
	}
	++e[cur];
}

int fd(string& s) {
	int cur{};
	for (char ch : s) {
		int path = ch - 'a';
		if (tr[cur][path] == 0) return 0;
		cur = tr[cur][path];
	}
	if (e[cur] > 0) {
		int tmp{e[cur]};
		e[cur] = -1;
		return tmp;
	}
	return e[cur];
}

void query(string& s) {
	int x{fd(s)};
	if (x == 0) {
		cout << "WRONG\n";
	} else if (x == -1) {
		cout << "REPEAT\n";
	} else {
		cout << "OK\n";
	}
}

int main() {
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		insert(s);
	}
	cin >> q;
	while (q--) {
		cin >> s;
		query(s);
	}

	return 0;
}
