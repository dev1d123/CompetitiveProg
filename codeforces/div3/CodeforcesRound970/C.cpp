#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int l, r; cin>>l>>r;
		
		int maxElem = 1 + sqrt(1 + 4 * 2 * (r - l));
		maxElem/=2;
		cout<<maxElem<<endl;
		
	}
	
	
	return 0;
}