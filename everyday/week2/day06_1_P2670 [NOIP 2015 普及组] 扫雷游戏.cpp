#include <bits/stdc++.h>
using namespace std;

const int N = 103;
int n, m;
string a[N];
int dx[8]{1, -1, 1, -1, 0, 0, 1, -1};
int dy[8]{1, -1, -1, 1, 1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i{1}; i <= n; ++i) {
        cin >> a[i];
        a[i] = "0" + a[i];
    }
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= m; ++j) {
            char cnt{'0'};
            if (a[i][j] == '?') {
                for (int k{}; k < 8; ++k) {
                    if (a[i + dx[k]][j + dy[k]] == '*') ++cnt;
                }
            }
            if (a[i][j] != '*') {
                a[i][j] = cnt;
            }
        }
    }
    for (int i{1}; i <= n; ++i) {
        for (int j{1}; j <= m; ++j) {
            cout << a[i][j];
        }
        cout << "\n";
    }


    return 0;
}