#include <bits/stdc++.h>
using namespace std;

void f(int n, char src, char dest, char temp) {
	if (n == 0) return;
	f(n - 1, src, temp, dest);
	cout << src << "->" << n << "->" << dest << "\n";
	f(n - 1, temp, dest, src);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int n; cin >> n;
	char src, dest, temp;
	cin >> src >> dest >> temp;
	f(n, src, dest, temp);	

	return 0;
}