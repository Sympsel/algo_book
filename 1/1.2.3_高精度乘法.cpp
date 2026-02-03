#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int A[N]{0};
int B[N]{0};
int C[N]{0};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	
	string a, b;
	cin >> a >> b;
	if (a == "0" || b == "0") {
		cout << "0\n";
		return 0;
	}
	
	// 读入数据
	int sz1(a.size()), sz2(b.size());
	for (int i{}; i < sz1; ++i) A[sz1 - 1 - i] = a[i] - '0';
	for (int i{}; i < sz2; ++i) B[sz2 - 1 - i] = b[i] - '0';
	
	for (int i{}; i < sz1; ++i) {
		for (int j{}; j < sz2; ++j) {
			C[i + j] += A[i] * B[j];
		}
	}

	// 处理进位
	for (int i{}; i < sz1 + sz2; ++i) {
		C[i + 1] += C[i] / 10;
		C[i] %= 10;
	}

	int sz{sz1 + sz2 - 1};
	while (sz > 0 && C[sz] == 0) {
		--sz;
	}
	
	for (int i{sz}; i >= 0; --i) {
		cout << C[i];
	}
	cout << "\n";

	return 0;
}