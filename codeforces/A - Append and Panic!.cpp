#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	set<char> st;
	for(char c: s){
		st.insert(c);
	}
	cout<<s.length() - st.size()<<endl;	
}