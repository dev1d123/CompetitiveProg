#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n; cin>>n;
    vector<ll> a(n);
    int q; cin>>q;
    for(int i = 0; i < n; i++) cin>>a[i];
    vector<ll> pre(n);
    pre[0] = a[0];
    for(int i = 1; i < n; i++) pre[i] = pre[i-1] + a[i];
    while(q--){
        int a, b; cin>>a>>b;
        if(a <= 1){
            cout<<pre[b-1]<<endl;
        }else{
            cout<<pre[b - 1] - pre[a-2]<<endl;
        }
    } 
}
