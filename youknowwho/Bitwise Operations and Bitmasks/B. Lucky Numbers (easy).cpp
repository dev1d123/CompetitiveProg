#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	string n; cin>>n;
	
	int len = n.length();
	if(len%2 == 1) len++;
	
	int ans = 0;
	int diff = LONG_LONG_MAX;
	for(int mask = 0; mask < (1 << len); mask++){
		string f;
		int b = 0;
		for(int i = 0; i < len; i++){
			if(mask & (1 << i)){
				f+='7';
				b++;
			}else{
				b--;
				f+='4';
			}
		}
		if(b == 0){
			int num = stoll(f);
			int in = stoll(n);
			if(num - in >= 0){
				diff = min(diff, num - in);
				if(diff == num - in){
					ans = num;
				}
			}
		}
	}
	if(ans != 0) {
		cout<<ans<<endl;
		return 0;
	}

	for(int mask = 0; mask < (1 << n.length() + 2); mask++){
		string f;
		int b = 0;
		for(int i = 0; i < n.length() + 2; i++){
			if(mask & (1 << i)){
				f+='7';
				b++;
			}else{
				b--;
				f+='4';
			}
		}
		if(b == 0){
			int num = stoll(f);
			int in = stoll(n);
			if(num - in >= 0){
				diff = min(diff, num - in);
				if(diff == num - in){
					ans = num;
				}
			}
		}
	}
	cout<<ans<<endl;

	
	
	return 0;
}