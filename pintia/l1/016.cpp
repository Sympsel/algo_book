#include <bits/stdc++.h>
using namespace std;

int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char m[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
const int N = 101;
int n;
vector<string> passed;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    string cur;
    for (int i{}; i < n; ++i) {
        cin >> cur;
        int sum{};
        for (int j{}; j < 17; ++j) {
            sum += (cur[j] - '0') * w[j];
        }
        if (m[sum % 11] != cur[17]) {
            passed.emplace_back(cur);
        }
    }

    if (passed.size() == 0) {
        cout << "All passed";
    } else {
        for (auto& str : passed) {
            cout << str << "\n";
        }
    }


    return 0;
}
