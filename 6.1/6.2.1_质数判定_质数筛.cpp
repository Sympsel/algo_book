#include <bits/stdc++.h>
using namespace std;

bool isprime(int n) {
    if (n == 1) return false;
    for (int i{2}; i <= n / i; ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int n; cin >> n;
    int x;
    while (n--) {
        cin >> x;
        if (isprime(x)) cout << x << " ";
    }

    return 0;
}