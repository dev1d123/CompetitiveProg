#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){

	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<pair<int, int>> arr(n);
		map<pair<int, int>, int> mp;
		
		int pos0 = 0;
		int pos1 = 0;
		for(int i = 0; i < n; i++){
			int a, b; 
			cin>>a>>b;
			arr[i] = make_pair(a, b);	
			if(b == 0){
				pos0++;
			}
			if(b == 1){
				pos1++;
			}
			mp[make_pair(a, b)] = 1;
		}
		int ans = 0;
		
		for(auto p: arr){
			int x = p.first;
			int y = p.second;
			int op;
			if(y == 1){
				op = 0;
			}else{
				op = 1;
			}
			
			if(mp[make_pair(x, op)] == 1){
				if(op == 1){
					ans+=pos1-1;
				}else{
					ans+=pos0-1;
				}	
			}
			
			int left = mp[make_pair(x-1, op)];
			int rigth = mp[make_pair(x+1, op)];
			if(left == 1 && rigth == 1){
				ans++;
			}	
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}