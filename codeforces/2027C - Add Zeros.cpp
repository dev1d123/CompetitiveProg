#include <bits/stdc++.h>
#define int long long

using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		map<int, vector<int>> adj;
		//how to determine if a problem is about DFS or graphs
		
		//Solo se puede empezar por un determinado nodo, modificar la ecuacion, solo se puede acceder a un nodo si se tiene una longitud.
		//los nodos repetidos no importan
		//luego establecer una relacion de nodo -> (condiciones) -> nodo
		
		for(int i = 1; i < n; i++){
			int u = arr[i] + i;
			int v = u + i;
			adj[u].push_back(v);
		}
		set<int> vis;
		function<void(int)> dfs = [&](int u) -> void{
			if(vis.count(u)) return;
			vis.insert(u);
			for(int v: adj[u]) dfs(v);
		};
		dfs(n);
		cout<<*vis.rbegin()<<endl;
		
	}
	
	return 0;
}