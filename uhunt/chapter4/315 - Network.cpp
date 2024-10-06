#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, int del) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if(neighbor == del) continue;

		if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, del	);
        }
    }
}

int cc(vector<vector<int>> &adj, int n, int del) {
    vector<bool> visited(n, false);
    int components = 0;
    for (int i = 0; i < n; i++) {
		if(i == del) continue;
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited, del);
        }
    }
    return components;
}

int solve(vector<vector<int>> &adj, int n){
	int ans = 0;
	int comp = cc(adj, n, -1);
	for(int i = 0; i < n; i++){
		int newComp = cc(adj, n, i);
		if(newComp > comp){
			ans++;
		}
	}
	return ans;
}


int main(){
	
	int n;
	while(cin>>n){
		cin.ignore();
		if(n == 0) break;
		vector<vector<int>> adj(n);
		int num; 
		while(cin>>num){
			if(num == 0) {
				int ans = solve(adj, n);
				cout<<ans<<endl;
				break;	
			}
			string nums;
			getline(cin, nums);
			stringstream ss(nums);
			string temp;
			num--;
			while(ss>>temp){
				int dir = stoi(temp);
				dir--;
				adj[num].push_back(dir);
				adj[dir].push_back(num);
			}
		}
	}
	return 0;
}