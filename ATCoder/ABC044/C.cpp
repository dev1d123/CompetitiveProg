#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 55;
ll dp[N][N * N];

signed main() {
    int N, A;
    cin>>N>>A;

    vector<int> arr(N); 
    for (int i = 0; i < N; i++) {
        cin>>arr[i]; 
    }
    dp[0][0] = 1; 
    
    for (int i = 0; i < N; i++) { 
        int x = arr[i]; 
        for (int j = i; j >= 0; j--) { 
            for (int k = 0; k <= 55 * 55; k++) { 
                dp[j + 1][k + x] += dp[j][k]; 
            }
        }
    }

    ll ans = 0; 
    for (int i = 1; i <= N; i++) {
        ans += dp[i][i*A];
    }
    cout << ans << endl; 
    return 0;
}
