#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int a, b; cin>>a>>b;

		int ans = 0;
		ans = ceil(b/2.0);
		
		int aSpaces;
		if(b%2 == 0){
			aSpaces = ans*7;
		}else{
			aSpaces = (ans-1)*7 + 11;
		}
		a = a - aSpaces;
		if(a > 0){
			ans += ceil(a/15.0);	
			cout<<ans<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
	
	
	return 0;
}