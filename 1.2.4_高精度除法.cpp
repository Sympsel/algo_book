#include <bits/stdc++.h>
using namespace std;

const int N{5005};
int A[N]{0};
int C[N]{0};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	string a;
	int b;
	cin >> a >> b;
	int sz(a.size());
	for (int i{}; i < sz; ++i) {
		A[i] = a[sz - 1 - i] - '0';
	}
	
	long long t{};
	for (int i{sz - 1}; i >= 0; --i) {
		t = t * 10 + A[i];
		C[i] = t / b;
		t %= b;
	}

	int j{sz - 1};
	while (j > 0 && C[j] == 0) {
		--j;
	}
	
	while (j >= 0) {
		cout << C[j];
		--j;
	}
	cout << "\n";

	return 0;
}