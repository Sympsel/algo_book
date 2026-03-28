#include <bits/stdc++.h>
using namespace std;


const int N = 1e3 + 7;
int a[N];
char op[N];
int n;
const int INF = 1e9 + 7;

int calc(int x, int y, int idx) {
    switch(op[idx]) {
    case '+':
        return x + y;
        case '-':
        return y - x;
        case '*':
        return x * y;
        case '/':
        return x == 0 ? INF : y / x;
    }
    return INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{n}; i >= 1; --i) cin >> a[i];
    for (int i{n}; i > 1; --i) cin >> op[i];

    for (int i{2}; i <= n; ++i) {
        int num1{a[i - 1]}, num2{a[i]};
        int ret{calc(num1, num2, i)};
        if (ret == INF) {
            cout << "ERROR: " << num2 << "/0\n";
            return 0;
        } else a[i] = ret;
    }
    cout << a[n] << "\n";

    return 0;
}
