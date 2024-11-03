#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int mod = 1000000007LL;
	int n, x; cin>>n>>x;
	vector<int> coins(n);
	
	for(int i = 0; i < n; i++){
		cin>>coins[i];	
	}
	sort(coins.begin(), coins.end());
	
	vector<int> dp(x + 1, 0);
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= x; j++){
			if(j - coins[i] >= 0){
				dp[j] = (dp[j] + dp[j-coins[i]])%mod;
			}
		}	
	}
	cout<<dp[x]%mod<<endl;
	return 0;
}