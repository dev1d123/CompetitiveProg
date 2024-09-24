#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int total; cin>>total;
		int b; cin>>b;
		vector<int> a(b);
		for(int i = 0; i < b; i++) cin>>a[i];
		bool ans = false;
		for(int mask = 0; mask < (1<<b); mask++){
			int sum = 0;
			for(int i = 0; i < b; i++){
				if(mask & (1<<i)){
					sum += a[i];
				}
			}
			if(sum == total){
				ans = true;
			}
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;	
			
	}
	
	
	return 0;
}