#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; cin>>s;
	if(s.length() == 2){
		if(s[0] == s[1]){
			cout<<1<<" "<<2<<endl;
			return 0;
		}
	}
	for(int i = 0; i < s.length() - 2; i++){
		set<char> w;
		w.insert(s[i]);
		w.insert(s[i+1]);
		w.insert(s[i+2]);
		if(w.size() <= 2){
			cout<<i + 1<<" "<<i + 3<<endl;
			return 0;
		}
	}
	cout<<-1<<" "<<-1<<endl;
	
	return 0;
}