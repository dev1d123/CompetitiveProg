#include <bits/stdc++.h>
using namespace std;
int main(){
	
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		
		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j < i; j++){
				int AND = i&j;
				if(AND < k) ans = max(ans, AND);
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
