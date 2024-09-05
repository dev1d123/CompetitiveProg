#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> v;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        mp[x]++;
    }

    int mini = v[0];
    for (int i = 0; i < n; i++) {
        mini = min(mini, v[i]);
    }

    if (mp[mini] == 1) {
        cout << "YES" << endl;
        return;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (v[i] % v[0]) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}