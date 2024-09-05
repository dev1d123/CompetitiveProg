#include <bits/stdc++.h>
using namespace std;
void DFSRec(vector<vector<int>> &adj, int initial, vector<bool> &valid, int &length){
	valid[initial] = true;
	length++;
	for(int neigth: adj[initial]){
		if(!valid[neigth]){
			DFSRec(adj, neigth, valid, length);
		}
	}
}
int DFS(vector<vector<int>> &adj, int n){
	vector<bool> valid(n, false);
	int ans = 0;
	for(int i = 0; i < n; i++){
		int length = 0;
		if(!valid[i]){
			DFSRec(adj, i ,valid, length);
		}
		ans = max(ans, length);
	}
	return ans;	
}
int main(){
	int n, m;
	stringstream output;
	while(cin>>n>>m){
		if(n == 0 && m == 0) break;
		vector<vector<int>> adj(n);
		int maxPPA = INT_MIN;
		
		vector<int>a(m);
		vector<int>b(m);
		vector<int>ppa(m);
		for(int i = 0; i < m; i++){
			cin>>a[i]>>b[i]>>ppa[i];
			maxPPA = max(maxPPA, ppa[i]);
		}
		for(int i = 0; i < m; i++){
			if(ppa[i] == maxPPA){
				adj[a[i] - 1].push_back(b[i] - 1);
				adj[b[i] - 1].push_back(a[i] - 1);
			}
		}
		//find the largest connected component!
		int ans = DFS(adj, n);
		//cout<<ans<<endl;	
		output<<ans<<endl;	
	}
	cout<<output.str();
	
	
	
	return 0;
}