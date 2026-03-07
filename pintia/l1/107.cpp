#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int out, st, in;
    cin >> out >> st >> in;
    if (out > 35 && (st == 1 || st == 0 && in >= 33))
        cout << "Bu Tie\n" << out;
    if (st == 0 && in < 33)
        cout << "Shi Nei\n" << out;
    if (st == 1 && out <= 35)
        cout << "Bu Re\n" << in;

    return 0;
}