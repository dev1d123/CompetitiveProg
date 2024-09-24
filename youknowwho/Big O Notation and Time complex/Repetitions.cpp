#include <bits/stdc++.h>
using namespace std;
int main(){
	string s; cin>>s;
	int ans = 0;
	for(int i = 0; i < s.length(); i++){
		int ch = s[i];
		int temp = 0;
		for(int j = i; j < s.length(); j++){
			if(s[j] != ch){
				i--;
				break;
			}
			i++;
			temp++;
		}
		ans = max(ans, temp);
	}
	cout<<ans<<endl;
	return 0;
}