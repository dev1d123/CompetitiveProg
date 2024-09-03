#include <bits/stdc++.h>
using namespace std;

int main(){
	string a, b,c;
	cin>>a>>b>>c;
	unordered_map<char, int> mp;
	
	unordered_map<char, int> mpA;
	unordered_map<char, int> mpB;
	
	for(char c: a) mpA[c]++;
	for(char c: b) mpB[c]++;
	for(char c: c) mp[c]++;
	
	for(auto it: mpA){
		if(mp[it.first] >= it.second){
			mp[it.first]-=it.second;
		}else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(auto it: mpB){
		if(mp[it.first] >= it.second){
			mp[it.first]-=it.second;
		}else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(auto it: mp){
		if(it.second != 0){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}