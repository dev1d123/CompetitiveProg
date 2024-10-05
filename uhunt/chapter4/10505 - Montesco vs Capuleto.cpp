#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<vector<int>> adj(n);
		for(int i = 0; i < n; i++){
			int num; cin>>num;
			for(int j = 0; j < num; j++){
				int ene; cin>>ene;
				if(ene > n) continue;
				ene--;
				adj[ene].push_back(i);
				adj[i].push_back(ene);
			}
		}
		vector<int> color(n, -1);
		int ans = 0;
		for(int s = 0; s < n; s++){
			bool isBipartite = true;
			if(color[s] != -1) continue;
			int c1 = 0;
			int c2 = 0;
			color[s] = 0;
			c1++;
			queue<int> q;
			q.push(s);
			while(!q.empty()){
				int u = q.front();
				q.pop();
				for(auto &v: adj[u]){
					if(color[v] == -1){
						color[v] = 1-color[u];
						if(1 - color[u] == 0) c1++;
						if(1 - color[u] == 1) c2++;	
						q.push(v);
					}else if(color[v] == color[u]){
						isBipartite = false;
						//break;
					}
				}
			}
			

			if(!isBipartite && (c1+c2 == 1)){
				ans++;
			}else if(isBipartite){
				ans += max(c1, c2);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}