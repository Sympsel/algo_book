#include <iostream>
using namespace std;

using ll = long long;
const int N = 61;
int n;
ll f[N];

int main() {
    cin >> n;
    ll a = 1, b = 2, c = 4;
    ll d{};

    if (n == 1) {
        cout << "1\n";
        return 0;
    }
    if (n == 2) {
        cout << "2\n";
        return 0;
    }
    if (n == 3) {
        cout << "4\n";
        return 0;
    }
    for (int i{4}; i <= n; ++i) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;  
    }
    cout << d << "\n";
    return 0;
}

