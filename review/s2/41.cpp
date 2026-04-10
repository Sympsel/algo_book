#include <bits/stdc++.h>
using namespace std;

const int N = 107;
const double EPS = 1e-7;
int n;
double a[N][N];

inline bool zero(const double& x) {
	return fabs(x) < EPS;
} 

int gauss() {
	for (int i{1}; i <= n; ++i) {
		int aim{i};
		for (int j{1}; j <= n; ++j) {
			if (j < i && !zero(a[j][j])) continue;
			if (fabs(a[j][i]) > fabs(a[aim][i])) aim = j;
		}

		if (zero(a[aim][i])) continue;

		for (int j{1}; j <= n + 1; ++j) swap(a[aim][j], a[i][j]);

		for (int j{n + 1}; j >= 1; --j) a[i][j] /= a[i][i];

		for (int j{1}; j <= n; ++j) {
			if (i == j) continue;
			double t{a[j][i]};
			for (int k{i}; k <= n + 1; ++k) a[j][k] -= t * a[i][k];
		}
	}

	int ret{1};
	for (int i{1}; i <= n; ++i) {
		if (zero(a[i][i]) && !zero(a[i][n + 1])) {
			ret = 0;
			break;
		}
		if (zero(a[i][i])) ret = 2;
	}
	return ret;
}

int main() {

	return 0;
}