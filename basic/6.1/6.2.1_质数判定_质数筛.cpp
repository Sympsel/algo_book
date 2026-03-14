#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int n;

bool isprime(const int& x) {
    if (x == 1) return false;
    for (int i{2}; i <= x / i; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, x; cin >> m;
    while (m--) {
        cin >> x;
        if (isprime(x))
            cout << x << " ";
    }
    cout << "\n";

    return 0;
}