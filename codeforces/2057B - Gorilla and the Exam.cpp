#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n, k; cin>>n>>k;
		vector<int> arr(n);
		map<int, int> mp;
		
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			mp[arr[i]]++;
		}
		vector<int> rep;
		int ans = mp.size();
		
		for(auto p: mp){
			rep.push_back(p.second);
		}
		sort(rep.begin(), rep.end());
		for(int i = 0; i < rep.size(); i++){
			if(k >= rep[i]){
				ans--;
				k-=rep[i];
			}else{
				break;
			}	
		}
		if(ans == 0){
			cout<<1<<endl;
		}else{
			cout<<ans<<endl;
		}		
	}
	
	
	return 0;
}