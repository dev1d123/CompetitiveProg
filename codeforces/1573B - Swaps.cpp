#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> a(n);
		vector<int> b(n);
		for(int i = 0; i < n; i++) cin>>a[i];
		for(int i = 0; i < n; i++) cin>>b[i];
		
		map<int, int> mp;
		int elemMax = 0;
		int impar = 1;
		for(int i = 0; i < n; i++){
			int par = b[i];
			if(b[i] > elemMax){
				elemMax = b[i];
				while(impar < elemMax){
					mp[impar] = i;
					impar+=2;
				}
			} 
		}
		/*
		cout<<"Mapa"<<endl;
		for(auto p: mp){
			cout<<p.first<<" -> "<<p.second<<endl;
		}
		*/
		int ans = INT_MAX;
		for(int i = 0; i < n; i++){
			ans = min(mp[a[i]] + i, ans);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}