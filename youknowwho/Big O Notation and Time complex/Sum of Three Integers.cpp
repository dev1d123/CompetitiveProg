#include <bits/stdc++.h>
using namespace std;
int main(){
	int k, s; cin>>k>>s;
	int ans = 0;
	for(int i = 0; i <= k; i++){
		for(int j = 0; j <= k; j++){
			if(i+j > s) break;
			int p = s - (i + j);
			if(p > k) continue;	
			else ans++;		
		}
	}
	cout<<ans<<endl;
	return 0;
}
