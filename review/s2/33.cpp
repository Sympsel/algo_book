#include <iostream>
using namespace std;

const int N = 507;
const int INF = 0x3f3f3f3f;
int n;
int a[N][N];
int f[N][N];

int main() {
    int n, m;
    while (cin >> n >> m) {
 		for (int i{1}; i <= n; ++i) {
 			for (int j{1}; j <= m; ++j) {
 				cin >> a[i][j];
 			}
 		}
 		for (int i{}; i <= n; ++i) f[i][0] = INF;
 		for (int i{}; i <= m; ++i) f[0][i] = INF;
 		f[0][1] = 0;

 		for (int i{1}; i <= n; ++i) {
 			for (int j{1}; j <= m; ++j) {
 				f[i][j] = a[i][j] + min(f[i - 1][j], f[i][j - 1]);
 			}
 		}
 		cout << f[n][m] << "\n";
    }
}