#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> a(n); 
    int used = 0;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        int u = (v + 1) / 2; 
        used += u;
        a[i] = {v, i}; 
    }
    if (used > w) {
        cout << -1 << endl;
        return 0;
    }
    sort(a.begin(), a.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first > p2.first;
    });

    vector<int> res(n); 
    for (int i = 0; i < n; i++) {
        int minRequired = (a[i].first + 1) / 2;
        res[a[i].second] = minRequired; 
    }

    int remaining = w - used; 

    for (int i = 0; i < n && remaining > 0; i++) {
        int maxAdd = a[i].first - res[a[i].second];
        int toAdd = min(maxAdd, remaining);
        res[a[i].second] += toAdd;
        remaining -= toAdd;
    }

    if (remaining < 0) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
