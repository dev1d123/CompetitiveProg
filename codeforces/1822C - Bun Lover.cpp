#include <bits/stdc++.h>
#define DBG(x) cerr<<#x<<": "<<x<<endl;
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int ans = (n - 3)*(n-3) + 8*(n-3) + 17;
		cout<<ans<<endl;
	}
	
	
	
	
	return 0;
}