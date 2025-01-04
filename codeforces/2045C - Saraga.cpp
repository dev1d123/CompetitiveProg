#include <bits/stdc++.h>
using namespace std;
int main(){
	string s1, s2; cin>>s1>>s2;
	if(s1.length() == 1 || s2.length() == 1){
		cout<<-1<<endl;
		return 0;
	}
	
	map<char, int> mp; 
	set<char> used;
	for (int i = 0; i < s2.length() - 1; i++) {
	    mp[s2[i]] = i; 
		used.insert(s2[i]);
	}
	
	
	int idx1=-1, idx2=-1;
	int minLen = INT_MAX;
	for(int i = 1; i < s1.length(); i++){
		if(used.count(s1[i])){
			
			int len = i + s2.length() - mp[s1[i]];
			if(len < minLen){
				minLen = len;
				idx1 = i;
				idx2 = mp[s1[i]];	
			}
		}
	}	
	
	if(idx1 == -1 || idx2 == -1){
		cout<<-1<<endl;
		return 0;
	} 
	string l = s1.substr(0, idx1);
	string r = s2.substr(idx2);
	string ans = l + r;

	//cout<<"idx1: "<<idx1<<endl;
	//cout<<"idx2: "<<idx2<<endl;
	cout<<ans<<endl;
	return 0;
}