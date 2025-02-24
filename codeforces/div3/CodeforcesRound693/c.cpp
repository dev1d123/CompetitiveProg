#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> w(n);
        for(int i = 0; i < n; i++){
            cin>>a[i];
            w[i] = a[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int nexInt = i + a[i];
            if(nexInt >= n) continue;
            w[nexInt] = max(w[nexInt], a[nexInt] + w[i]);
        }
        for(int num: w){
            ans = max(ans, num);
        }
        cout<<ans<<endl;
    }



    return 0;
}