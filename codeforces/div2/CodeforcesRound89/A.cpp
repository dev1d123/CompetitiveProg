#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'; 
}
int main(){
	string s; cin>>s;
	string str = "";
	for(char c: s){
		str += tolower(c);
	}
	string ans = "";
	for(char c: str)
		if(!isVowel(c)){
		
			ans += '.';
			ans += c;
		}
	cout<<ans<<endl;
	
	return 0; 
}