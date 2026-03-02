#include <bits/stdc++.h>
using namespace std;

int fd(vector<int>& arr, int tar) {
    int l{}, r((int)arr.size() - 1);
    while (l < r) {
        int mid{(l + r + 1) / 2};
        if (arr[mid] < tar) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string num; cin >> num;
    priority_queue<int> q;
    unordered_set<int> s;
    vector<int> idx, arr;
    for (auto& ch : num) {
        int x(ch - '0');
        if (!s.count(x)) {
            q.emplace(x);
            s.emplace(x);
        }
    }
    while (q.size()) {
        int t{q.top()}; q.pop();
        arr.emplace_back(t);
    }

    int ns(num.size());
    for (int i{}; i < ns; ++i) {
        idx.emplace_back(fd(arr, num[i] - '0'));
    }
    int as(arr.size()), is(idx.size());
    cout << "int[] arr = new int[]{";
    for (int i{}; i < as; ++i) {
        if (i == as - 1) cout << arr[i];
        else cout << arr[i] << ",";
    }
    cout << "};\nint[] index = new int[]{";
    for (int i{}; i < is; ++i) {
        if (i == is - 1) cout << idx[i];
        else cout << idx[i] << ",";
    }
    cout << "};";

    return 0;
}
