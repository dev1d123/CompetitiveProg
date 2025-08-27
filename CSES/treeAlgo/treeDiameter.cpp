#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dp;
vector<int> vis;
vector<vector<int>> adj;


pair<int, int> solve(int n){
    vis[n] = 1;
    int b1 = 0;
    int b2 = 0;

    //multiset<int> st;
    
    for(int son: adj[n]){
        if(vis[son] == 1) continue;
        pair<int, int> res = solve(son);
        int h = max(res.first, res.second);
        if(h > b1){
            b2 = b1;
            b1 = h;
        }else if(h > b2){
            b2 = h;
        }
        //st.insert(max(res.first, res.second));
    }
    /*
    auto it = st.end();      
    if(st.size() >= 2){
        it--;
        b1 = *it;
        it--;
        b2 = *it;
        b1++;
        b2++;
    }else if(st.size() == 1){
        it--;
        b1 = *it;
        b1++;
    }
    */
    b1++;
    if(b2 > 0) b2++;

    dp[n] = {b1, b2};
    return {b1, b2};
}


int main(){
    int n; cin>>n;
    dp.assign(n, {0,0});
    vis.assign(n, 0);
    adj.assign(n, vector<int>());
    for(int i = 1; i < n; i++){
        int u,v; cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    solve(0);
    int ans = 0;

    for(int i = 0; i < n; i++){
        ans = max(ans, dp[i].first + dp[i].second - 2);
    }
    cout<<ans<<endl;

}
