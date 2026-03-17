#include <bits/stdc++.h>
using namespace std;

int n, p1, p2;
int mp[5][5]{
    {0, 0, 1, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 1, 0, 0, 0}
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> p1 >> p2;
    vector<int> seq1(p1);
    vector<int> seq2(p2);
    for (int i{}; i < p1; ++i) cin >> seq1[i];
    for (int i{}; i < p2; ++i) cin >> seq2[i];
    int cnt1{}, cnt2{};
    for (int i{}; i < n; ++i) {
        int x{seq1[i % p1]}, y{seq2[i % p2]};
        if (mp[x][y] == 1) {
            ++cnt1;
        } else if (mp[y][x] == 1) {
            ++cnt2;
        } else {}
    }
    cout << cnt1 << " " << cnt2 << "\n";
    return 0;
}


// 神人打表方式
// #include <bits/stdc++.h>
// using namespace std;

// int n, p1, p2;
// map<pair<int, int>, int> mp;

// void init() {
//     mp[{0, 0}] = 0; mp[{1, 0}] = 1; mp[{2, 0}] = 0; mp[{3, 0}] = 0; mp[{4, 0}] = 1;
//     mp[{0, 1}] = 0; mp[{1, 1}] = 0; mp[{2, 1}] = 1; mp[{3, 1}] = 0; mp[{4, 1}] = 1;
//     mp[{0, 2}] = 1; mp[{1, 2}] = 0; mp[{2, 2}] = 0; mp[{3, 2}] = 1; mp[{4, 2}] = 0;
//     mp[{0, 3}] = 1; mp[{1, 3}] = 1; mp[{2, 3}] = 0; mp[{3, 3}] = 0; mp[{4, 3}] = 0;
//     mp[{0, 4}] = 0; mp[{1, 4}] = 0; mp[{2, 4}] = 1; mp[{3, 4}] = 1; mp[{4, 4}] = 0;
// }

// int main() {
//     init();
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n >> p1 >> p2;
//     vector<int> seq1(p1);
//     vector<int> seq2(p2);
//     for (int i{}; i < p1; ++i) cin >> seq1[i];
//     for (int i{}; i < p2; ++i) cin >> seq2[i];
//     int cnt1{}, cnt2{};
//     for (int i{}; i < n; ++i) {
//         int x{seq1[i % p1]}, y{seq2[i % p2]};
//         pair<int, int> a{x, y};
//         pair<int, int> b{y, x};
//         if (mp[a] == 1) {
//             ++cnt1;
//         } else if (mp[b] == 1) {
//             ++cnt2;
//         } else {}
//     }
//     cout << cnt1 << " " << cnt2 << "\n";
//     return 0;
// }
