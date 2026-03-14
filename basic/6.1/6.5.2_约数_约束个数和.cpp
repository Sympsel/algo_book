#include <iostream>

using namespace std;

int main() {


    int n; cin >> n;
    int ret{};
    for (int i{1}; i <= n / 2; ++i) {
        ret += n / i;
    }
    ret += n - n / 2;

    cout << ret << "\n";
    return 0;
}