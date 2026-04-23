#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        cout << static_cast<char>(toupper(str[0]));
    }
    return 0;
}
