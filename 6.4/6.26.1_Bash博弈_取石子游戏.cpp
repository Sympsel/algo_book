#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, k;
    cin >> n >> k;
    if (n % (k + 1)) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }
    return 0;
}