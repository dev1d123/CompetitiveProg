#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int a,b; cin>>a>>b;
		string s1,s2; cin>>s1>>s2;
		int ans = 0;
		int last = 0;
		for(int i = 0; i < a; i++){
			bool is = false;
			for(int j = last; j < b; j++){
				if(s1[i] == s2[j]){
					is = true;
					last = j+1;
					break;
				}
			}
			if(is){
				ans++;
			}else{
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}