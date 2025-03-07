#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(auto &it: a) cin>>it;
        int ans = 0;

        for(int i = 0; i < n - 1; i++){
            if(a[i]%2 == a[i+1]%2) {
                ans++;
            }
        }
        cout<<ans<<endl;
    }



    return 0;
}