#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> a(n); 
		vector<int> b(n);
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		for(int i = 0; i < n; i++){
			cin>>b[i];
		}
		//logic!
		int j = 0;
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(b[i] >= a[j]){
				//no pasa nada
				j++;
			}else{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}