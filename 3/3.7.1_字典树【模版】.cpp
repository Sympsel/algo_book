#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int N = 3e6 + 3;
int tr[N][62];
int idx;
int p[N];
int n, q;

int get_id(const char& ch) {
	if (islower(ch)) {
		return ch - 'a';
	}
	if (isupper(ch)) {
		return ch - 'A' + 26;
	}
	return ch - '0' + 52;
}

void insert(const string& s) {
	int cur{};
	++p[cur];

	for (auto ch : s) {
		int id{get_id(ch)};
		if (tr[cur][id] == 0)
			tr[cur][id] = ++idx;
		cur = tr[cur][id];
		++p[cur];
	}
}

void query(const string& s) {
	int cur{};
	for (auto ch : s) {
		int id{get_id(ch)};
		if (tr[cur][id] == 0) {
			cout << "0\n";
			return;
		}
		cur = tr[cur][id];
	}
	cout << p[cur] << "\n";
}

void solve() {
	cin >> n >> q;
	string s;
	while (n--) {
		cin >> s;
		insert(s);
	}

	while (q--) {
		cin >> s;
		query(s);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int t; cin >> t;
	while (t--) {
		for (int i{}; i <= idx; ++i)
			for (int j{}; j < 62; ++j)
				tr[i][j] = 0;
		for (int i{}; i <= idx; ++i)
			p[i] = 0;
		idx = 0;
		solve();
	}

	return 0;
}