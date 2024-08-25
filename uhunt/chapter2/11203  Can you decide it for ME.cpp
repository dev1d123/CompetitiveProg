#include <bits/stdc++.h>
using namespace std;
bool valid(string &s){
	int idx1=50	, idx2=0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] != '?' && s[i] != 'M' && s[i] != 'E'){
			return false;
		}
		if(s[i] == 'M'){
			if(idx1==50){
				idx1 = i;
			}else{
				return false;
			}
		}
		if(s[i] == 'E'){
			if(idx2==0){
				idx2 = i;	
			}else{
				return false;
			}
		}
	}
	if(idx1 > idx2 || idx1 == 0 || idx2 == s.length() - 1|| abs(idx1-idx2) == 1){
		return false;
	}
	return true;
}
int main(){
	
	int t; cin>>t;
	stringstream output;
	while(t--){
		string s; cin>>s;
		if(!valid(s)){
			output<<"no-theorem"<<endl;
			continue;
		}
		bool b1 = false, b2 = false;
		int a=0,b=0,c=0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == 'M' && !b1){
				b1 = true;
				continue;
			}
			if(s[i] == 'E' && !b2){
				b2 = true;
				continue;
			}
			if(b2 && b1){
				c++;
			}
			if(b1 && !b2){
				b++;
			}
			if(!b1 && !b2){
				a++;
			}
			
		}
		if(a+1 == c && b==1){
			output<<"theorem"<<endl;
		}else{
			int n1 = a;
			
			int n2 = a + 1;
			
			int n3 = b - 1;
			
			if(c - n2 == n3){
				output<<"theorem"<<endl;
			}else{
				output<<"no-theorem"<<endl;	
			}
		}
	}
	cout<<output.str();
	return 0;
}

