#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string transform_k(const string& s, ll k) {
    int n = s.size();
    string res = s;
    ll offset = 1LL << k;
    for (int i = n - 1; i >= 0; --i) {
        if (i >= offset) {
            res[i] = ((s[i] - '0') ^ (s[i - offset] - '0')) + '0';
        } else {
            res[i] = s[i];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    int n;
    ll t;
    string str;
    cin >> n >> t >> str;
    
    string ans = str;
    
    for (int k = 0; k < 60; ++k) {
        if ((t >> k) & 1) {
            string temp = ans;
            ll offset = 1LL << k;
            for (int i = 0; i < n; ++i) {
                if (i >= offset) {
                    ans[i] = ((temp[i] - '0') ^ (temp[i - offset] - '0')) + '0';
                } else {
                    ans[i] = temp[i];
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}