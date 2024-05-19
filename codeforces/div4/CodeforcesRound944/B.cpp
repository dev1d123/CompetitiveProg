#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		char c1=' ', c2=' ';
		int i1=-1, i2=-1;
		int index = 0;
		for(char c: s){
			if(c1 == ' '){
				c1 = c;
				i1 = index;
			}
			if(c1 != ' ' && c2 == ' ' && c1 != c){
				c2 = c;
				i2 = index;
			}
			index++;
		}
		if(i2 != -1){
			cout<<"YES"<<endl;
			char temp = s[i1];
			s[i1] = s[i2];
			s[i2] = temp;
			cout<<s<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}