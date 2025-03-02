#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        map<int, int> mp;
        int m = INT_MAX;
        for(int i = 0; i<n;i++){
            int x; cin>>x; mp[x]++;
            m=min(m, x);
        }
        cout<<n-mp[m]<<endl;
    }


    return 0;
}