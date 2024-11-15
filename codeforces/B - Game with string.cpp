#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; cin>>s;
	stack<char> st;
	
	int t = 0;
	for(char ch: s){
		if(!st.empty() && st.top() == ch){
			st.pop();
			t++;
		}else{
			st.push	(ch);	
		}
	}
	if(t%2 == 1){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	
	return 0;
}