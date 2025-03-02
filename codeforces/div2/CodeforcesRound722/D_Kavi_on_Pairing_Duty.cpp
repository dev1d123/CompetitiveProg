#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;
    int mod =998244353;
    vector<int> dp(n+1);
    dp[0] = 1;
    vector<int> div(1e6+1, 0); 
    for(int i = 1; i <= n; i++){
        for(int j = i+i; j<=n; j+=i){
            div[j]++;
        }
    }
    int sum = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = (sum+div[i])%mod;
        sum = (sum+dp[i])%mod;
    }
    cout<<dp[n];
    

    return 0;
}