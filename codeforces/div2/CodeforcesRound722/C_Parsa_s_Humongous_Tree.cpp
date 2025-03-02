#include <bits/stdc++.h>
using namespace std;
#define int long long
int n = 1e5+5;
vector<pair<int, int>> lr;
vector<vector<int>> dp(n, vector<int>(2));
vector<vector<int>> adj(n);
void dfs(int u, int p){
    for(int v: adj[u]){
        if(v == p) continue;;
        dfs(v,u);
    }
    for(int v: adj[u]){
        if(v==p) continue;
        dp[u][0] += max(abs(lr[u].first - lr[v].first) + dp[v][0], 
                        abs(lr[u].first - lr[v].second) + dp[v][1]);
        dp[u][1] += max(abs(lr[u].second - lr[v].first) + dp[v][0], 
                        abs(lr[u].second - lr[v].second) + dp[v][1]);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        lr.assign(n, {0, 0});
        
        for(int i=0; i<n; i++)adj[i].clear(), dp[i][0]=dp[i][1]=0;

        for(int i = 0; i < n; i++){
            int l, r; cin>>l>>r;
            lr[i] = {l, r};
        }        
        for(int i = 0; i < n-1; i++){
            int u,v; cin>>u>>v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        cout<<max(dp[0][0], dp[0][1])<<endl;
    }
    return 0;
}