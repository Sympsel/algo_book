// #include <bits/stdc++.h>
// using namespace std;

// vector<pair<int, int>> tab;
// int ak, a0, cnt0, k0;
// const int N = 1e5 + 7;
// int cnt[N];

// int bin_search(int x) {
//     int l{}, r{tab.size() - 1};
//     while (l < r) {
//         int mid{(l + r) / 2};
//         if (tab[mid].first < x) {
//             l = mid + 1;
//         } else {
//             r = mid;
//         }
//     }
//     return l;
// }

// inline int getCnt(int x) {
//     int cur{bin_search(x)};
//     double k{};
//     if (cur == (int)tab.size()) k = k0;
//     else k = 1.f * (tab[cur - 1].second - tab[cur].second) / (tab[cur].first - tab[cur - 1].first);
//     return tab[cur - 1] -  k * (x - tab[cur - 1]);
// }


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> ak >> a0 >> cnt0;
//     tab.emplace_back(a0, cnt0);
//     cnt[a0] = cnt0;
//     int ai, cnti;
//     while (cin >> ai >> cnti, ai != -1) {
//         tab.emplace_back(ai, cnti);
//         cnt[ai] = cnti;
//     }
//     for (int i{a0}; i <= n; ++i) {
//         if (cnt[i] == 0) {
//             cnt[i] = getCnt(i);
//         }
//     }
//     tab.sort(tab.begin(), tab.end());
//     double min_x{0x3f3f3f3f}, max_x{-0x3f3f3f3f};
//     int i{a0};
//     for (; i < ak; ++i) {
//         min_x = min(min_x, (1.f * (i - a0) * cnt[i] - (ak - a0)) / (cnt[i] - cnt[]));
//     }
//     cin >> k0;


//     return 0;
// }
