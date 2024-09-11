#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		map<int, int> ans;
		for(int i = 0; i < n; i++){
			int num; cin>>num;
			int value = num - (i + 1);
			ans[value]++;
		}
		ll res = 0;
		for(auto p: ans){
			ll x = p.second - 1;
			res += (x*(x+1))/2;
		}
		cout<<res<<endl;
	}
	
	return 0;
}