#include <bits/stdc++.h>
#define DBG(x) cerr<<#x<<": "<<x<<endl;
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		double n; cin>>n;
		int x, y; cin>>x>>y;
		int ans = max(ceil(n/y), ceil(n/x));
		cout<<ans<<endl;
	}
	
	
	
	
	return 0;
}