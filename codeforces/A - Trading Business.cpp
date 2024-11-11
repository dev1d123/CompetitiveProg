#include <bits/stdc++.h>
using namespace std;
bool compareByBenefit(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
    return get<0>(a) > get<0>(b); // Orden descendente basado en el beneficio
}
 
int main(){
	int n, m, k;
	cin>>n>>m>>k;
	vector<vector<tuple<int, int, int>>> data(n);
	
	for(int i = 0; i < n; i++){
		string name; cin>>name;
		for(int j = 0; j < m; j++){
			int a,b,c;
			cin>>a>>b>>c;
			data[i].push_back({a, b, c});
		}
	}
	
 
    int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			vector<tuple<int, int, int, int>> waos(m); 
			for(int e = 0; e < m; e++){
				waos[e] = {get<1>(data[j][e]) - get<0>(data[i][e]), get<0>(data[i][e]), get<1>(data[j][e]), get<2>(data[i][e])};	
			}
			sort(waos.begin(), waos.end(), compareByBenefit);
		    int precio = 0;
		    int ganancia = 0;
		    int used = k;
		    for (const auto& item : waos) {
		    	if(get<0>(item) > 0){
		    		int compr = 0;
					if(get<3>(item) <= used){
		    			compr = get<3>(item);
					}else{
						compr = used;
					}
					
					used-=compr;
					precio += compr*get<1>(item);
					ganancia += compr*get<2>(item);
				}else{
					break;
				}
			}
 
			ans = max(ans, ganancia-precio);
		}
		
	}
	cout<<ans<<endl;
	return 0;
}