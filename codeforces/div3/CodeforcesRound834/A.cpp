#include <bits/stdc++.h>
using namespace std;
int main(){
	string yes = "Yes";
	while(yes.length() <= 1000){
		yes+="Yes";
	}
	int t; cin>>t;
	while(t--){
		string in; 
		cin>>in;
		if(yes.find(in) != string::npos){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}