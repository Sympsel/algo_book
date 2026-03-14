#include <bits/stdc++.h>
using namespace std;

// int gcd(int a, int b) {
//     return b == 0 ? a : gcd(b, a % b);
// }

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    while (b) {
        int new_b = a % b;
        a = b;
        b = new_b;
    }
    return a;
}

int gcd(int a, int b, int c) {
    return gcd(a, gcd(b, c));
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << gcd(a, b, c) << "\n";


    return 0;
}