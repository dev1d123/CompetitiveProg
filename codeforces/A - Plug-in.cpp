#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; cin>>s;
	
	stack<char> st;
	for(int i = 0; i < s.length(); i++){
		if(!st.empty()){
			if(st.top() != s[i]){
				st.push(s[i]);
			}else{
				st.pop();
			}	
		}else{
			st.push(s[i]);	
		}
	}
	string ans = "";	
	while(!st.empty()){
		ans += st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	cout<<ans<<endl;	
	
	

	return 0;
}