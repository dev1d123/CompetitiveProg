#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007;
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result%MOD;
}
signed main(){
    int t; cin>>t; 
    while(t--){
        int n; cin>>n;
        int inv = (n * (n - 1)) % MOD;
        int fact = factorial(n);
        int ans = (fact * inv) % MOD;
        cout<<ans<<endl;
    }


    return 0;
}