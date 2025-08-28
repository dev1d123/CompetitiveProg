#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    multiset<pair<int, int>> mo;
    for(int i = 0; i < n; i++){
        int x,y; cin>>x>>y;
        mo.insert({y,x});
    }
    multiset<int> wa;
    for(int i = 0; i < k; i++) wa.insert(0);
    int ans = 0;
    for(auto &[l, r]: mo){
        auto it = wa.upper_bound(r);
        if(it == wa.begin()) continue;
        --it;
        wa.erase(it);
        wa.insert(l);
        ans++;
    }

    cout<<ans<<endl;
}
