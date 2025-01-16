#include <bits/stdc++.h>
#define DBG(x) cerr<<#x<<": "<<x<<endl;
#define int long long
using namespace std;
signed main(){
	int q; cin>>q;
	while(q--){
		int n; cin>>n;
		vector<int> a; 
		
		for(int i = 0; i < n; i++){
			int v; cin>>v;
			a.push_back(v);
			
		}
		sort(a.begin(), a.end());
		
		int ans = LLONG_MIN;
		for(int i = 0; i < a.size() - 1; i++){
			ans = max(ans, a[i]*a[i+1]);	
		}
		
		cout<<ans<<endl;
	}
	
	
	
	
	return 0;
}