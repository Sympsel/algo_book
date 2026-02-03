#include <bits/stdc++.h>
using namespace std;

unordered_set<string> hs;

string tar{"123804765"};
string src;

string gsw(const string& str, int i, int j) {
	string ret{str};
	char tm{ret[i]};
	ret[i] = ret[j];
	ret[j] = tm;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> src;
	int idx(src.find('0'));
	queue<string> q;
	q.emplace(src);
	hs.emplace(src);
	int ret{};
	while (q.size()) {
		++ret;
		int sz(q.size());
		
		while (sz--) {
			string str{q.front()}; q.pop();
			int idx(str.find('0'));
			int mv[4] = {idx - 1, idx + 1, idx - 3, idx + 3};
			for (int i{}; i < 4; ++i) {
				int j{mv[i]};
				if ((i == 0 && idx % 3 == 0) ||
					(i == 1 && idx % 3 == 2) ||
					j < 0 || j >= 9
					/*(i == 2 && idx < 3) ||*/
					/*(i == 3 && idx > 5)*/) continue;
				string cur{gsw(str, idx, j)};
				if (hs.count(cur)) continue;
				if (cur == tar) {
					cout << ret << "\n";
					return 0;
				}
				hs.emplace(cur);
				q.emplace(cur);	
			}
		}
	}
	cout << "0\n";
	return 0;
}