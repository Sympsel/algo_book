#include <bits/stdc++.h>
using namespace std;

bool isprime(int x) {
    if (x < 2) return false;
    for (int i{2}; i <= x / i; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a; cin >> n;
    while (n--) {
        cin >> a;
        if (isprime(a)) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
