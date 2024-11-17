#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n, m; cin>>n>>m;
		map<pair<int, int>, int> mp;
		vector<pair<int, int>> arr(m);
		for(int i = 0; i < m; i++){
			int x, w; cin>>x>>w;
			arr[i] = {x, w};
			mp[{x, w}] = i;
		}
		sort(arr.begin(), arr.end());
		vector<pair<int, int>> arrAux(m);

		for(int i = 0; i < m; i++){
			arrAux[i] = {arr[i].second, arr[i].first};
		}
		sort(arrAux.begin(), arrAux.end());

		vector<pair<int, int>> ans;
		int res = 0;
		for(int i = 0; i < m; i++){
			if(i + 1 <= 2*n){
				ans.push_back({arrAux[i].second, mp[{arrAux[i].second, arrAux[i].first}]});
				res += arrAux[i].first;
			}
		}
		sort(ans.begin(), ans.end());

		cout<<res<<endl;
		for(int i = 0; i < n; i++){
			cout<<ans[i].second + 1<<" "<<ans[2*n - i - 1].second + 1<<endl;
		}
		
	}
	
	
	return 0;
}