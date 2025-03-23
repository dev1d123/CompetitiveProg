#include <bits/stdc++.h>
using namespace std;
int main(){

	string s, t;
	cin>>s>>t;

	int idx1 = 0;
	int idx2 = 0;

	while(idx1 < s.length()){
		if(s[idx1] == t[idx2]){
			cout<<idx2+1<<" ";
			idx1++;
			idx2++;
		}else{
			idx2++;
		}
	}
	cout<<endl;
	return 0;	
}
