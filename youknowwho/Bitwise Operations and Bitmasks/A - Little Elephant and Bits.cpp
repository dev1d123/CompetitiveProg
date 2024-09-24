#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; cin>>s;
	string ans = "";
	bool f = true;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '0' && f){
			f = false;
			continue;
		}else{
			ans += s[i];
		}
	}
	if(ans.length() == s.length()){
		ans = ans.substr(0, ans.length() - 1);
	}
	cout<<ans<<endl;
	
	
	return 0;
}