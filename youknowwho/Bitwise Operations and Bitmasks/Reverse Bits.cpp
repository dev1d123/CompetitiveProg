#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		unsigned int n; cin>>n;
		unsigned int ans = 0;
		int j = 0;
		for(int i = 31; i >= 0; i--){
			if(n&(1<<j)){
				ans = ans | (1 << i);
			}
			j++;
		}

		cout<<ans<<endl;
	}	
	return 0;
}