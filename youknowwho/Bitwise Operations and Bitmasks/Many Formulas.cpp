#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	string s; cin>>s;
	int pos = 0;
	int ansTotal = 0;
	for(int mask = 0; mask < (1 << (s.length() - 1)); mask++){
		string num = string(1, s[0]);
		int ans = 0;
		for(int i = 1; i < s.length(); i++){
			if(mask & (1 << s.length() - 1 - i)){
				ans += stoll(num);
				num = string(1, s[i]);
			}else{
				num += s[i];
			}
		}
		ans += stoll(num);
		ansTotal += ans;
	}
	cout<<ansTotal<<endl;
	return 0;
}