#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		string s; cin>>s;
		stack<char> st1; 
		int bal = 0;
		
		for(int i = 0; i < n; i++){
			if(s[i] == '('){
				bal++;
			}else if(s[i] == ')'){
				bal--;
			}else if(s[i] == '_'){
				if(bal == 0){
					s[i] = '(';
					bal++;
				}else if(bal > 0){
					s[i] = ')'; 
					bal--;
				}
			}
		}
		int ans = 0;
		stack<pair<int, char>> res;
		
		for(int i = 0; i < n; i++){
			if(s[i] == '('){
				res.push(make_pair(i, '('));
			}else if(s[i] == ')'){
				if(!res.empty()){
					pair<int, char> parsito = res.top();
					res.pop();
					ans += abs(parsito.first - i);
				}
			}
		
		} 
		
		cout<<s<<": "<<ans<<endl;
	}
	
	return 0;
}

