#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; cin>>s;
	string num = "";
	if(s.length() == 1){
		num = s[0];
	}else{
		num = s.substr(s.length() - 2, 2); 	
	}
	int p = stoi(num);
	
	if(p%4 == 0){
		cout<<4<<endl;
	}else{
		cout<<0<<endl;
	}
	
	
	return 0;
}