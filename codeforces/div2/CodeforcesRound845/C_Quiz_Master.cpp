#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 100000;
vector<vector<int>> factors(M + 1);

void precomputeFactors() {
    for (int i = 1; i <= M; i++) {
        for (int j = i; j <= M; j += i) {
            factors[j].push_back(i);
        }
    }
}

int findMinDifference(vector<int> &arr, int m) {
    int n = arr.size();
    vector<int> freq(m + 1, 0);
    int topics_covered = 0;
    int res = LLONG_MAX;
    int j = 0;
    
    for (int i = 0; i < n; i++) {
        while (j < n && topics_covered < m) {
            for (int x : factors[arr[j]]) {
                if (x <= m) {
                    freq[x]++;
                    if (freq[x] == 1) topics_covered++;
                }
            }
            j++;
        }
        
        if (topics_covered == m) {
            res = min(res, arr[j - 1] - arr[i]);
        }
        
        for (int x : factors[arr[i]]) {
            if (x <= m) {
                freq[x]--;
                if (freq[x] == 0) topics_covered--;
            }
        }
    }
    
    return (res == LLONG_MAX ? -1 : res);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precomputeFactors();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (auto &it : arr) cin >> it;
        sort(arr.begin(), arr.end());
        cout << findMinDifference(arr, m) << endl;
    }
    return 0;
}
