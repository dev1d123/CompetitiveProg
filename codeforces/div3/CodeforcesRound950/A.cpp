#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int m,n; cin>>m>>n;
		string a; cin>>a;
		map<char, int> mp;
		for(char c: a){
			mp[c]++;
		}
		int ans = 0;
		string pr = "ABCDEFG";
		for(int i = 0; i < n; i++){
			for(char p: pr){
				if(mp[p] == 0){
					ans++;
				}else{
					mp[p]--;
				}	
			}
			
			 
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
