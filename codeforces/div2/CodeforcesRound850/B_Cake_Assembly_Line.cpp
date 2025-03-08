#include <bits/stdc++.h>

using namespace std;

const int inf = 1000000000;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int minS = -inf;
    int maxS = inf;
    for (int i = 0; i < n; i++) {
      minS = max(minS, (b[i] + h) - (a[i] + w));
      maxS = min(maxS, (b[i] - h) - (a[i] - w));
    }
    if (minS <= maxS) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}