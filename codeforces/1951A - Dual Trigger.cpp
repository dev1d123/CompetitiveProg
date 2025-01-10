#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		string s;
		cin>>s;
		int one = 0;
		for(char ch: s){
			if(ch == '1')one++;
		}
		//si la cantidad de one es 2, y aparecen pegados...es imposible
		if(one == 2){
			bool ans = true;
			for(int i = 0; i < n; i++){
				if(s[i] == '1' && s[i+1] == '1'){
					ans = false;
					break;
				}
			}
			if(!ans){
				cout<<"NO"<<endl;
				continue;
			}
		}
		if(one%2 == 0)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}