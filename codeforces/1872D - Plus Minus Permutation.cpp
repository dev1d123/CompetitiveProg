#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int n, x, y;
		cin>>n>>x>>y;
		int f = n/x;
		int s = n/y;
		int mcm = x*y/__gcd(x,y);
		int t = n/mcm;
		f-=t;
		s-=t;
		
		int pr = f*(2*n - f + 1)/2;
		int sc = (s*(s+1))/2;
		cout<<pr-sc<<endl;
	}
	
	
	
	return 0;
}