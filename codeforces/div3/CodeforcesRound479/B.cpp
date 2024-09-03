#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n>>s;
	map<string, int> mp;
	
	int most = 0;
	for(int i = 0; i < n - 1; i++){
		string tg = string(1, s[i]) + s[i+1];
		mp[tg]++;
		most = max(most, mp[tg]);
	}
	for(auto it: mp){
		if(it.second == most){
			cout<<it.first<<endl;
			break;
		}
	}
	
	
	return 0;
}
