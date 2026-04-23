#include <bits/stdc++.h>
using namespace std;

bool zero(float x) {
    return x < 1e-18;
}

int main() {
    float a;
    char b;
    cin >> a >> b;
    int ret{20};    
    if (b == 'y') {
        ret += 5;
    }
    if (a >= 1) {
        a -= 1;
    } else {
        cout << ret << "\n";
        return 0;
    }
    if (!zero(a)) {
        ret += ceil(a);
    }
    cout << ret << "\n";

    return 0;
}
