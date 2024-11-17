#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vector<ii>> Graph; 
const int INF = 1e9;


vi dijkstra(int s, Graph &AL, int V){
	vi dist(V, INF);
	dist[s] = 0;
	
	set<ii> pq; 
	for(int u = 0; u < V; u++){
		pq.emplace(dist[u], u);
	}
	
	while(!pq.empty()){
		auto [d, u] = *pq.begin();
		pq.erase(pq.begin());
		for(auto &[v, w]: AL[u]){
			if(dist[u] + w >= dist[v]) continue;
			pq.erase(pq.find({dist[v], v}));
			dist[v] = dist[u] + w;
			pq.emplace(dist[v], v); 
		}		
	}	
	return dist;
}

int main(){
	int t; cin>>t;
	stringstream output;
	while(t--){
		int V; cin>>V;
		int e;	
		int t;
		cin>>e>>t;
		e--;
		
		int num; cin>>num;
		Graph AL(V); 

		while(num--){
			int a, b, w; cin>>a>>b>>w;
			a--; b--;
			AL[a].emplace_back(b, w);
		}	
		int ans = 0;
        for(int i = 0; i < V; i++){
        	vi dist = dijkstra(i, AL, V);
			if(dist[e] <= t){
				ans++;
			}
		}
		output<<ans<<endl;    
		output<<endl;    
	}
    string result = output.str();
    if (!result.empty() && result.back() == '\n') {
        result.pop_back(); 
    }
    cout << result; 
	return 0;
}