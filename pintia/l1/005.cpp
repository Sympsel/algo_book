#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;

struct node {
    long long id;
    int a, b;

    node(long long _id, int _a, int _b) : id(_id), a(_a), b(_b) {}
};

vector<node> stus;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long id; int a, b;
    cin >> n;
    while (n--) {
        cin >> id >> a >> b;
        stus.emplace_back(id, a, b);
    }
    sort(stus.begin(), stus.end(), [](const node& A, const node& B) {
        return A.a < B.a;
    });

    cin >> m;
    int x, l, r;
    while (m--) {
        cin >> x;
        l = 0, r = (int)stus.size() - 1;
        while (l < r) {
            int mid{(l + r + 1) / 2};
            if (x >= stus[mid].a) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << stus[l].id << " " << stus[l].b << "\n";
    }

    return 0;
}
