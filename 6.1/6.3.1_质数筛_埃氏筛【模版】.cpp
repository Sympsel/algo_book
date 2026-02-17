#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 7;
int n;
bool st[N];
vector<int> p;

int main() {
    cin >> n;
    for (int i{2}; i <= n; ++i) {
        if (st[i]) continue;
        p.emplace_back(i);
        if (i <= n / i)
            for (int k{i * i}; k <= n; k += i)
                st[k] = true;
    }
    for (const auto& _ : p)
        cout << _ << " ";
    cout << "\n";
    return 0;
}
