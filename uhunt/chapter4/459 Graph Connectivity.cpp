#include <bits/stdc++.h>

using namespace std;

void DFSRec(vector<vector<int>> &adj, int initial, vector<bool> &visited){
	visited[initial] = true;
	
	for(int nodes: adj[initial]){
		if(!visited[nodes]){
			DFSRec(adj, nodes, visited);	
		}
	}
	
}
void DFS(vector<vector<int>> &adj, int &ans){
	vector<bool> visited(adj.size(), false);
	
	for(int i = 0; i < adj.size(); i++){
		if(!visited[i]){
			ans++;
			DFSRec(adj, i, visited);
		}
	}
}



int cti(char c){
	return c-'A';
}
int main(){
	int t; cin>>t;
	t++;
	cin.ignore();
	int waos = t;
	stringstream output; 	
	vector<vector<int>> adj;
	map<pair<int, int>, bool> mp;
	while(true){
		string data;
		getline(cin, data);
		if(data == ""){
			if(waos == t){
				t--;
				continue;
			}
			t--;

			int ans = 0;
			DFS(adj, ans);
			output<<ans<<endl;
			if(t == 0){
				break;
			}else{
				output<<endl;
			}
			adj.clear();
            mp.clear();
			continue;	
		}
		if(data.length() == 1){
			adj.resize(cti(data[0]) +1);
		}else{
            int u = cti(data[0]);
            int v = cti(data[1]);
			
			int a = max(u, v);
			int b = min(u, v);
			
			if(!mp[make_pair(a,b)]){
				adj[a].push_back(b);
            	adj[b].push_back(a);
            	mp[make_pair(a,b)] = true;
			}

		}
		
		if(t == 0) break;
	}
	cout<<output.str();
	
	return 0;
}