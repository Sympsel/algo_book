#include <algorithm>
#include <iostream>
using namespace std;

const int N = 31;

pair<int, int> a[N];
int n;
int idx;

void dfs(int root) {
  if (root < 0 || root >= n)
    return;
  dfs(root * 2 + 1);
  dfs(root * 2 + 2);
  a[idx++].first = root;
}

int main() {
  cin >> n;
  dfs(0);
  for (int i{}; i < n; ++i)
    cin >> a[i].second;
  sort(a, a + n);
  for (int i{}; i < n; ++i)
    cout << a[i].second << " \n"[i == n - 1];
  return 0;
}
