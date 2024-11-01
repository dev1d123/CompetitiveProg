#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(m, vector<int>(4));
	int ans = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < 4; j++){
			int val; cin>>val;
			v[i][j] = val;
		}
	}
	for(int i = 1; i <= n; i++){
		//por cada seccion
		int winner = 0;
		int time = INT_MAX;
		vector<pair<int, int>> mrd;

		for(int j = 0; j < m; j++){
			//si el atleta corre
			
			if(v[j][0] <= i && v[j][1] >= i){
				time = min(time, v[j][2]);
				mrd.push_back({v[j][2], v[j][3]});
			}
			
		}
		for(auto p: mrd){
			if(p.first == time){
				winner = p.second;
				break;
			}
		}
		ans += winner;
	}
	cout<<ans<<endl;
	
	return 0;
}