#include <bits/stdc++.h>
using namespace std;


vector<vector<pair<int, int>>> AL;
int n;
vector<int> dist;
int INF = 1e9;

void dijkstra(int start){
	dist.assign(n, INF);
	dist[start] = 0;
	
	set<pair<int, int>> pq;
	for(int u = 0; u < n; u++){
		pq.emplace(dist[u], u);
	}
	while(!pq.empty()){
		auto [d, u] = *pq.begin();
		pq.erase(pq.begin());
		for(auto [v, w]: AL[u]){
			if(dist[u] + w >= dist[v]) continue;
			pq.erase(pq.find({dist[v], v}));
			dist[v] = dist[u] + w;
			pq.emplace(dist[v], v);
		}
		
	}

}


int main(){
	int N; cin>>N;
	int c = 1;
	while(N--){
		int m, s, t;
		cin>>n>>m>>s>>t;
		AL.assign(n, vector<pair<int, int>>());
		while(m--){
			int a, b, w;
			cin>>a>>b>>w;
			AL[a].emplace_back(b, w);
			AL[b].emplace_back(a, w);

		}
		dijkstra(s);
		int ans = dist[t];
		cout<<"Case #"<<c++<<": ";
		if(ans == INF){
			cout<<"unreachable"<<endl;;	
		}else{
			cout<<ans<<endl;
		}
		AL.clear();
		dist.clear();
		
	}
	
	
	
	return 0;
}