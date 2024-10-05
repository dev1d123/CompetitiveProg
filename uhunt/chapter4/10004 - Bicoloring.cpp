#include <bits/stdc++.h>
using namespace std;
const int INF = -1;
void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}
int main(){
	fastIO();
	int n;
	while(cin>>n){
		if(n == 0) break;
		int m;
		cin>>m;
		vector<vector<int>> adj(n);
		for(int i = 0; i < m; i++){
			int u, v;
			cin>>u>>v;
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		int s = 0;
		queue<int> q;
		q.push(s);
		vector<int> color(n, INF);
		color[s] = 0;
		bool isBipartite = true;
		while(!q.empty() && isBipartite){
			int u = q.front();
			q.pop();
			for(auto &v: adj[u]){
				if(color[v] == INF){
					color[v] = 1 - color[u];
					q.push(v);
				}else if(color[v] == color[u]){
					isBipartite = false;
					break;
				}
			}
		}
		if(!isBipartite) cout<<"NOT BICOLORABLE.\n";
		else cout<<"BICOLORABLE.\n";
		
	}	
	return 0;
}
	