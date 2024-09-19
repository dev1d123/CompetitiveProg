#include <bits/stdc++.h>
using namespace std;

vector<int> dp(41, -1);


map<int, int> primeFactor(int n){
	map<int, int> mp;
	for(int i = 2; i*i <= n; i++){
		while(n%i == 0){
			n/=i;
			mp[i]++;
		}
	}
	if (n > 1) {
        mp[n]++;
    }
	return mp;
}
void fib(){	
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2; i <= 40; i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
}
int main(){
	int t; cin>>t;
	fib();
	while(t--){
		int n, a, b; 
		cin>>n>>a>>b;
		int expA = dp[n-1];
		int expB = dp[n];
		map<int, int> da = primeFactor(a);
		for(auto p: da) da[p.first] = p.second * expA;
		map<int, int> db = primeFactor(b);
		for(auto p: db) db[p.first] = p.second * expB;
		map<int, int> ans;
		for(auto p: da) ans[p.first] += p.second;
		for(auto p: db) ans[p.first] += p.second;
		
		for(auto p: ans) cout<<p.first<<" "<<p.second<<endl;
		
		cout<<endl;
	}
}