#include <bits/stdc++.h>
using namespace std;
int ctoi(char c){
	return c - 'a' + 1;
}
int main(){
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		char first = s[0];
		char last = s[s.length() - 1];
		vector<int> rute;
		
		map<char, vector<int>> waos;
		
		set<int> st;
		
		for(int i = 0; i < s.length(); i++){
			st.insert(s[i]);
			waos[s[i]].push_back(i+1);
		}
		string w;
		for(char ch: st){
			w += ch;
		}
		//cout<<"string: "<<w<<endl;
		
		int posStart=-1, posEnd=-1;
		
		for(int i = 0; i < w.length(); i++){
			if(w[i] == first) posStart = i;
			if(w[i] == last) posEnd = i;
		}
		
		//cout<<"ps: "<<posStart<<endl;
		//cout<<"pe: "<<posEnd<<endl;
		
		if(posStart < posEnd){
			for(int i = posStart; i <= posEnd; i++){ 
				for(int num: waos[w[i]]){
					rute.push_back(num);
				}
			}
		}else{
			for(int i = posStart; i >= posEnd; i--){
				for(int num: waos[w[i]]){
					rute.push_back(num);
				}
			}
		}
		
		cout<<abs(ctoi(first)-ctoi(last))<<" "<<rute.size()<<endl;
		for(int num: rute){
			cout<<num<<" ";
		}
		cout<<endl;
		
	}
	
	return 0;	
}