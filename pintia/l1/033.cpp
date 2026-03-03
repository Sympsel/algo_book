#include <bits/stdc++.h>
using namespace std;

unordered_set<int> s;
int num, k;

bool addtoset(int x) {
    s.clear();
    if (to_string(x).size() < 4) s.emplace(0);
    while (x) {
        s.emplace(x % 10);
        x /= 10;
    }
    return s.size() != k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> num >> k;
    int x{};
    for (int i{num}; addtoset(i); ++i) ++x;
    cout << x << " " << setfill('0') << setw(4) << (num + x);


    return 0;
}
