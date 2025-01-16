#include <bits/stdc++.h>
#define DBG(x) cerr<<#x<<": "<<x<<endl;
using namespace std;
int main(){
	int q; cin>>q;
	while(q--){
		int n, t; cin>>n>>t;
		vector<int> a(n); 
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		for(int i = 0; i < n; i++){
			cin>>b[i];
		}
		int ans = -1;
		int maxE = 0;
		for(int i = 0; i < n; i++){
			if(i + a[i] <= t){
				if(b[i] > maxE){
					ans = i+1;
					maxE = b[i];
				}
			}
		}
		
		cout<<ans<<endl;
	}
	
	
	
	
	return 0;
}