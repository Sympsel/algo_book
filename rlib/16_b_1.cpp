#include <bits/stdc++.h>
using namespace std;

int main() {
    double r = sqrt(233 * 233 + 666 * 666);
    double th = atan(1.0 * 666 / 233);
    cout << (int)(r * (1 + th)) << endl;
    return 0;
}
