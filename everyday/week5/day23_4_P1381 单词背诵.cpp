#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 1e5 + 7;
int n, m;
unordered_set<string> tar;
string words[M];
int cnt, ret;

int retL, retLen;
bool check(int x) {
    cnt = ret = 0;
    unordered_map<string, int> cnts;
    int l{1}, r{1}, cnt{};
    bool solved{};
    while (r <= m) {
        while (l <= r && !tar.count(words[l])) ++l;
        if (tar.count(words[r])) {
            ++cnts[words[r]];
            if (cnts[words[r]] == 1) {
                ++cnt;
                if (retLen < r - l + 1) {
                    retLen = r - l + 1;
                    retL = l;
                }

                if (cnt >= x) solved = true;
            }
        }
        while (cnts.size() == cnt) {
            --cnts[words[l]];
            if (cnts[words[l]] == 0) {
                cnts.erase(words[l]);
                --cnt;
            }
            ++l;
        }
        ++r;
    }
    return solved;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    string _;
    for (int i{1}; i <= n; ++i) {
        cin >> _;
        tar.emplace(_);
    }
    cin >> m;
    for (int i{1}; i <= m; ++i) cin >> words[i];
    int l{}, r{n};
    while (l < r) {
        int mid{(l + r + 1) / 2};
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << "\n" << retLen << "\n";
    return 0;
}