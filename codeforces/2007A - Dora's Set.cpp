#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		
		int l, r; cin>>l>>r;
		
		int ans = 0;
		while(l <= r){
			if(l%2 == 1 && (r - l + 1 )>= 3){
				ans++;
				l+=4;
			}else{
				l++;
			}
		}
		
		cout<<ans<<endl;
	}
		
	return 0;
}