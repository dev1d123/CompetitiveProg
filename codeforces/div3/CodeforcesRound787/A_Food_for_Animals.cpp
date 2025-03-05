#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int a,b,c,x,y;
        cin>>a>>b>>c>>x>>y;
        x = max(0LL, x-a);
        y = max(0LL, y-b);
        if(x+y > c){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}