#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int a, b, c;
		cin>>a>>b>>c;
		int ans = (abs(a-b) + 2*c - 1 )/(2*c);
		cout<<ans<<endl;
	}
	
	
	return 0;
}