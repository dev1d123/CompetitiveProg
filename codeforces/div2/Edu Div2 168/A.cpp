#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		bool fl = false;
		for(int i = 0; i < s.length() - 1; i++){
			string c;
			if(s[i] == s[i+1]){
				if(s[i] == 'a'){
					c = "b";
				}else{
					c = "a";
				}
				cout<<s.substr(0, i+1).append(c).append(s.substr(i+1))<<endl;
				fl = true;
				break;
			}
		}
		if(fl) continue;
		
		
		if(s[0] == 'a'){
			string c = "b";
			cout<<c.append(s);
		}else{
			string c = "a";
			cout<< c.append(s);
		}
		cout<<endl;
	}
	
	
	return 0;
}

