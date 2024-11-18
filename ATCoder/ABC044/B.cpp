#include <bits/stdc++.h>
using namespace std;
int main(){
	string w; cin>>w;
	map<char, int > xd;
	for(char c: w){
		if(islower(c)){
			xd[c]++;
		}
	}
	for(auto p: xd){
		if(p.second%2 != 0){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	
	
	return 0;
}