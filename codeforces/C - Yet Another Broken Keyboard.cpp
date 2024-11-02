#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n, k; cin>>n>>k;
	string s; cin>>s;
	map<char, bool> mp;
	for(int i = 0; i < k; i++){
		char v; cin>>v;
		mp[v] = true;
	}
	
	int count = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(!mp[s[i]]){
			ans += (count*(count + 1) )/ 2;
			count = 0;
		}else{
			count++;
		}	
	}
	if(count != 0){
		ans += (count*(count + 1) )/ 2;
	}
	cout<<ans<<endl;
	return 0;
}