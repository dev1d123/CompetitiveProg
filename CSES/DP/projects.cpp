#include <bits/stdc++.h>
using namespace std;

using ll = long long;
bool comp(tuple<ll, ll, ll> &a, tuple<ll, ll, ll> &b){
    auto &[a1,a2,a3] = a;
    auto &[b1,b2,b3] = b;
    return (a2 < b2);
}

int main(){
    int n; cin>>n;
    vector<tuple<ll, ll, ll>> a;
    for(int i = 0; i < n; i++){
        int ai,bi,pi; cin>>ai>>bi>>pi;
        a.emplace_back(ai,bi,pi);
    }
    sort(a.begin(), a.end(), comp);
    vector<ll> cord;
    for(auto &[x,y,z]: a){
        cord.emplace_back(y);
    }
    vector<ll> dp(n + 1, 0);
    
    for(int i = 1; i <= n; i++){
        auto &[a1, a2, a3] = a[i-1];
        int j = (int)(upper_bound(cord.begin(), cord.end(), a1 - 1) - cord.begin());
        dp[i] = dp[i-1];    
        dp[i] = max(dp[i], dp[j] + a3);
    }
    cout<<dp[n]<<endl;
}

/*
dp[i] = max(dp[i-1], dp[prev(i)] + p[i]);
prev is the index of the last proyect that ends before the start of project i
this can be solve with binary search.
*/
