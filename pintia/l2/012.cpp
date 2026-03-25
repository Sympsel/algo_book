#include <bits/stdc++.h>
using namespace std;

int n;

unordered_map<int, int> mp;

struct Heap {
    vector<int> _a;

    void adjust_down(int parent, int sz) {
        int child = parent * 2 + 1;
        while (child < sz) {
            if (child + 1 < sz && _a[child + 1] < _a[child]) {
                ++child;
            }

            if (_a[child] < _a[parent]) {
                swap(_a[child], _a[parent]);
                parent = child;
                child = parent * 2 + 1;
            } else break;
        }
    }

    void adjust_up(int child) {
        while (child > 0) {
            int parent{(child - 1) / 2};
            if (_a[child] < _a[parent]) {
                swap(_a[child], _a[parent]);
                child = parent;
            } else break;
        }
    }

    void output() {
        for (int i{}; i < (int)_a.size(); ++i) {
            mp[_a[i]] = i;
        }
    }

    void insert(int x) {
        _a.emplace_back(x);
        adjust_up(_a.size() - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> a;
    int m;
    cin >> n >> m;

    int _;
    Heap hp;
    for (int i{}; i < n; ++i) {
        cin>> _;
        hp.insert(_);
    }
    cin.ignore();

    hp.output();
    int x, y;
    string line;
    while (m--) {
        getline(cin, line);
        if (line.find("root") != string::npos) {
            sscanf(line.c_str(), "%d is the root", &x);
            if (mp[x] == 0) cout << "T\n";
            else cout << "F\n";
        } else if (line.find("and") != string::npos) {
            sscanf(line.c_str(), "%d and %d are siblings", &x, &y);
            if ((mp[x] - 1) / 2 == (mp[y] - 1) / 2) cout << "T\n";
            else cout << "F\n";
        } else if (line.find("parent") != string::npos) {
            sscanf(line.c_str(), "%d is the parent of %d", &x, &y);
            if ((mp[y] - 1) / 2 == mp[x]) cout << "T\n";
            else cout << "F\n";
        } else if (line.find("child") != string::npos) {
            sscanf(line.c_str(), "%d is a child of %d", &x, &y);
            if (mp[x] == mp[y] * 2 + 1 || mp[x] == mp[y] * 2 + 2) cout << "T\n";
            else cout << "F\n";
        } else {}
    }
    return 0;
}
