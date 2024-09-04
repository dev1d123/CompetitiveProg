#include <bits/stdc++.h>
using namespace std;
void DFSRec(vector<vector<int>> &adj, vector<bool> &visit, int initial, int &ans){
	visit[initial] = true;
	ans++;

	for(int node: adj[initial]){
		if(!visit[node]){
			DFSRec(adj, visit, node, ans);
		}
	}
}
int main(){
	int t; cin>>t;
	while(t--){
		int n,m,l;
		cin>>n>>m>>l;
		
		vector<vector<int>> adj(n);
		for(int i = 0; i < m; i++){
			int x, y;
			cin>>x>>y;
			x--;
			y--;
			adj[x].push_back(y);
		}
		vector<bool> visit(n, false);
		int ans = 0;
		for(int i = 0; i < l; i++){	
			int dom; cin>>dom;
			dom--;				
           if (!visit[dom]) { 
                DFSRec(adj, visit, dom, ans);
            }
		}
		cout<<ans<<endl;
	}
	return 0;
}