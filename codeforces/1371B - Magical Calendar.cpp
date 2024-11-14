#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int n, r; cin>>n>>r;
		if(n <= r){
			cout<<(n*(n-1))/2 + 1<<endl;
		}else{
			//n > r
			cout<<(r*(r+1))/2<<endl;
		}
	}
	
	return 0;
}