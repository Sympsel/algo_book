#include <bits/stdc++.h>
#include <string>
using namespace std;

inline int tostamp(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

inline string toformat(int stamp) {
    string ret;
    int h{stamp / 3600};
    stamp %= 3600;
    int m{stamp / 60};
    int s{stamp % 60};
    char buffer[9];
    sprintf(buffer, "%02d:%02d:%02d", h, m, s);
    return buffer;
}

int n;
using pii = pair<int, int>;
priority_queue<pii, vector<pii>, greater<pii>> q;
vector<pii> ret;


int main() {
    cin >> n;
    if (n == 0) {
        cout << "00:00:00 - 23:59:59\n";
        return 0;
    }
    const int END{tostamp(23, 59, 59)};
    char _;
    for (int i{}; i < n; ++i) {
        int h1, m1, s1, h2, m2, s2;
        cin >> h1 >> _ >> m1 >> _ >> s1
            >> _
            >> h2 >> _ >> m2 >> _ >> s2;
        int t1{tostamp(h1, m1, s1)};
        int t2{tostamp(h2, m2, s2)};
        if (t1 < t2) {
            q.emplace(t1, t2);
        } else if (t1 > t2) {
            q.emplace(0, t2);
            q.emplace(t1, END);
        } else {
            // at least a second
        }
    }
    int begin{q.top().first};
    while ((int)q.size() >= 2) {
        auto [t1_b, t1_e] {q.top()}; q.pop();
        auto [t2_b, t2_e] {q.top()};
        if (t1_e < t2_b) {
            ret.emplace_back(t1_e, t2_b);
        }
    }
    int end{q.top().second};
    q.pop();
    if (begin) {
        cout << "00:00:00 - " << toformat(begin) << "\n";
    }
    for (auto [b, e] : ret) {
        cout << toformat(b) << " - " << toformat(e) << "\n";
    }
    if (end < END) {
        cout << toformat(q.top().second) << " - " << "23:59:59" << "\n";
    }
    return 0;
}
