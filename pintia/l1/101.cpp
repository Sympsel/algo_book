#include <bits/stdc++.h>
using namespace std;

const int N = 104;
int n, k;
string a[N];
const string rrep{"<censored>"};
const string rep{"你好"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i{}; i < n; ++i) cin >> a[i];
    cin >> k;
    cin.ignore();
    string str;
    getline(cin, str);

    bool flag{};
    int cnt{};

    size_t pos{};
    // while (pos < str.size()) {
    //     bool fd{};
    //     for (int i{}; i < n; ++i) {
    //         if (pos + a[i].size() <= str.size() && str.substr(pos, a[i].size()) == a[i]) {
    //             ++cnt;
    //             str.replace(pos, a[i].size(), rep);
    //             pos += rep.size();
    //             fd = true;
    //             break;
    //         }
    //     }
    //     if (!fd) ++pos;
    // }

    do {
        flag = false;
        for (int i{}; i < n; ++i) {
            // while ((pos = str.find(a[i], pos)) != string::npos) {
            //     str = str.replace(pos, a[i].size(), rep);
            //     ++cnt;
            //     flag = true;
            // }

            size_t pos{str.find(a[i])};
            if (pos == string::npos) continue;
            str = str.replace(pos, a[i].size(), rep);
            ++cnt;
            flag = true;
            break;
        }
    } while (flag);

    // cout << str << "\n";
    pos = 0;
    while ((pos = str.find(rep, pos)) != string::npos) {
        str = str.replace(pos, rep.size(), rrep);
    }
    if (cnt >= k) {
        cout << cnt << "\n" << "He Xie Ni Quan Jia!";
    } else {
        cout << str;
    }


    return 0;
}