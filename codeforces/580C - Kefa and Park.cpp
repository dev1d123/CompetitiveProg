#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> cats;
vector<int> consec;
int m;
int ans = 0;
void dfsRec(int s, int par){
	vis[s] = true;
	if(s == 0){
		consec[s] = cats[s];
		
	}else{
		if(cats[s] == 1 && cats[par] == 1){
			consec[s] = consec[par] + 1;
		}else if(cats[s] == 1){
			consec[s] = 1;
		}else{
			consec[s] = 0;
		}
	}
	
	if(consec[s] > m){
		return;	
	}

	if(adj[s].size() <= 1  && s != 0){
    	if (consec[s] <= m) ans++;
	}
	
	for(int v: adj[s]){
		if(vis[v] == false){
			dfsRec(v, s);
		}
	
	}
}

int main(){
	int n;
	cin>>n;
	cin>>m;
	cats.assign(n, 0);
	adj.assign(n, vector<int>());
	consec.assign(n, 0);
	for(int i = 0; i < n; i++){
		cin>>cats[i];
	}
	
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin>>u>>v;
		u--; v--;
		adj[u].push_back(v);	
		adj[v].push_back(u);	

	}
	vis.assign(n, false);
	dfsRec(0, -1);
	cout<<ans<<endl;
	
	
}