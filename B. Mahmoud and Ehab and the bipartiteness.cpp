#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> adj;
map<int, int> tr;

signed main(){
	int n; cin>>n;
	int c = 0;
	adj.assign(n, vector<int>());
	set<int> st;
	
	for(int i = 0; i < n - 1; i++){
		int u, v; cin>>u>>v;			
        if (tr.count(u) == 0) tr[u] = c++;
        if (tr.count(v) == 0) tr[v] = c++;
		adj[tr[u]].push_back(tr[v]);
		adj[tr[v]].push_back(tr[u]);
		st.insert(tr[u]);
		st.insert(tr[v]);
	}
	//encontrar el nodo raiz	
	int root = 0;
	
	vector<int> lvCount;
	vector<bool> vis(n, false);
	queue<int> q;
	q.push(root);
	vis[root] = true;
	while(!q.empty()){
		int lvSize = q.size();
		lvCount.push_back(lvSize);
		
		for(int i = 0; i < lvSize; i++){
			int current = q.front();
			q.pop();
			for(int neight: adj[current]){
				if(!vis[neight]){
					vis[neight] = true;
					q.push(neight);
				}
			}
		}
	}	
	int ans = 0;

	
	for (int i = lvCount.size() - 1; i >= 0; i--) {
        int lv = i;
        int partial = 0;
	    if (i - 1 >= 0) {
	        ans += lvCount[i] * (lvCount[i - 1] - 1);
	    	partial += lvCount[i] * (lvCount[i - 1] - 1);
		}
		for(int j = i - 3; j >= 0; j-=2){
			ans += lvCount[i]*lvCount[j];
			partial += lvCount[i]*lvCount[j];
		}
	}
	cout<<ans<<endl;
	
	
	return 0;
}