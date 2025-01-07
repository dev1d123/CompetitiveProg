#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		vector<int> arr(n);
		map<int, int> mp;
		map<int, int> rep;
		
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			
			rep[arr[i]]++;
		}
		sort(arr.begin(), arr.end());
		
		for(int i = 0; i < n; i++){
			if(mp.find(arr[i]) == mp.end()){
				mp[arr[i]] = i;
			}
		}
		
		vector<int> un;
		for(auto p: mp){
			un.push_back(p.first);
		}
		int cans = 0;
		int press = 0;
		for(int i = 0; i < un.size(); i++){
			int possible;
			if(i == 0){
				possible = (un[i])*n;
			}else{
				possible = (un[i] - un[i-1])*(n - mp[un[i]]);

			}
		
			if(cans + possible >= k){
				int needed = k - cans;
				press += needed;
				cans = k;
				break;
			}else{
				cans += possible;
				press += rep[un[i]];
				press += possible;
			}
		}
		cout<<press<<endl;
	}
	
	
	return 0;
}