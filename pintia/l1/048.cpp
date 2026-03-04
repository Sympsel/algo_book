#include <bits/stdc++.h>
using namespace std;

const int N = 103;
int A[N][N];
int B[N][N];
int C[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b;
    for (int i{1}; i <= a; ++i)
        for (int j{1}; j <= b; ++j)
            cin >> A[i][j];
    cin >> c >> d;
    for (int i{1}; i <= c; ++i)
        for (int j{1}; j <= d; ++j)
            cin >> B[i][j];
    if (b != c) {
        cout << "Error: " << b << " != " << c;
        return 0;
    }
    for (int i{1}; i <= a; ++i) {
        for (int j{1}; j <= d; ++j) {
            for (int k{1}; k <= c; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << a << " " << d << "\n";
    for (int i{1}; i <= a; ++i) {
        for (int j{1}; j <= d; ++j) {
            if (j > 1) cout << " ";
            cout << C[i][j];
        }
        cout << "\n";
    }

    return 0;
}
