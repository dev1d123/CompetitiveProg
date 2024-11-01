#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a = 0;
		int b = 0;
		bool ans = true;
		for(int i = 0; i < n; i++){
			int p, c;
			cin>>p>>c;
			if(p - a >= 0 && c - b >= 0 && p-a>=c-b){
				
			}else{
				ans = false;
			}
			a = p;
			b = c;
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	
	return 0;
}