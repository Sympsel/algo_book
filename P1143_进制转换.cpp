#include <bits/stdc++.h>
using namespace std;

int n;
string num;
int m;

string dn{"0123456789ABCDEF"};
map<char, int> nd;

void init() {
	for (int i{}; i < 10; ++i) {
		nd[i + '0'] = i;
	}
	for (int i{10}; i < 16; ++i) {
		nd[i - 10 + 'A'] = i;
	}
}

int NtoD() {
	int ret{};
	int len(num.size());
	for (int i{}; i < len; ++i) {
		ret += nd[num[len - 1 - i]] * pow(n, i);
	}
	return ret;
}

string DtoM(int x) {
	string ret;
	while (x) {
		ret += dn[x % m];
		x /= m;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	init();
	
	cin >> n >> num >> m;
	cout << DtoM(NtoD()) << "\n";

	return 0;
}