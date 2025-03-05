#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n; 
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    int sum1 = 0, sum2 = 0;
    int idx1 = 0, idx2 = n - 1;
    int maxS = 0;
    while (idx1 <= idx2) {
        if (sum1 < sum2) {
            sum1 += arr[idx1++];
        } else {
            sum2 += arr[idx2--];
        }
        if (sum1 == sum2) {
            maxS = sum1; 
        }
    }
    cout << maxS << endl;

    return 0;
}
