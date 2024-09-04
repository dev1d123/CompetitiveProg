#include <bits/stdc++.h>
using namespace std; 
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		map<char, int> waos;
		waos['0'] = 0;
		waos['1'] = 0;
		waos['2'] = 0;
		waos['3'] = 0;
		waos['4'] = 0;
		waos['5'] = 0;
		waos['6'] = 0;
		waos['7'] = 0;
		waos['8'] = 0;
		waos['9'] = 0;
		for(int i = 1; i <= n; i++){
			string num = to_string(i);
			for(char c: num){
				waos[c]++;
			}
		}
		int w = 0;
		for(auto p: waos){
			if(w == 0){
				cout<<p.second;
			}else{
				cout<<" "<<p.second;
			}
			w++;
		}
		cout<<endl;
	}
	
	
	return 0;
}