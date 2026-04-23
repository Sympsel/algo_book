
#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    int _min{0x3f3f3f3f};
    char _tc{};
    for (char ch{'a'}; ch <= 'z'; ++ch) {
        int sum{};
        for (auto& c : s) {
            int x = abs((int)ch - (int)c);
            x = min(x, 26 - x);
            sum += abs(x);
        }
        if (sum < _min) {
            _min = sum;
        }
    }
    cout << _min << "\n";
    return 0;
}
