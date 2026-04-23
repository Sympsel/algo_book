#include <bits/stdc++.h>
using namespace std;

const int N = 1e3  + 7;
int a[N][N];
int b[N][N];
    int n; 

void T(int* a[]) {
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n; ++j) {
            b[j][i] = a[i][j];
        }
    }
}

int main() {
    cin >> n;
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    int q;
    int opa, opb;
    cin >> q;
    while (q--) {
        int c; cin >> c;
        if (c == 1) {
            ++opa;
        } else if (c == 2) {
            ++opb;
        } else {}
    }
    opa %= 4;
    opb %= 2;
    return 0;
}