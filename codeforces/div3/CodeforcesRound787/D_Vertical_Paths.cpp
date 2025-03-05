#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<bool> &vis, int node, vector<vector<int>> &ans, int &idx) {    
    vis[node] = true;
    if (idx >= ans.size()) ans.resize(idx + 1);
    ans[idx].push_back(node);
    
    if (adj[node].empty()) {  
        idx++;
    }
    
    for(int neigh: adj[node]){
        if(vis[neigh]) continue;
        dfs(adj, vis, neigh,ans,idx);
    }
    /*
        
    */
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> adj(n);
        int root = 0;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            x--;
            if(x == i) root = x;
            else adj[x].push_back(i);
        }
        vector<bool> vis(n, false);
        int count = 0;
        vector<vector<int>> ans;
        dfs(adj, vis, root, ans,count);
        cout<<ans.size()<<endl;
        for (auto &group : ans) {
            cout << group.size() << endl;
            for (int node : group) {
                cout << node + 1 << " ";  
            }
            cout << endl;
        }
    }


    return 0;
}