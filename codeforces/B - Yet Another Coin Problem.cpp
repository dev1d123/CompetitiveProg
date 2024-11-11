#include <bits/stdc++.h>
using namespace std;
 
vector<int> dp(101, 101);
 
int solve(vector<int> &coins, int n){
	
	for(int i = 1; i < n+1; i++){
		for(int c: coins){
			if(i - c >= 0){
				dp[i] = min(dp[i], 1 + dp[i - c]);
			}
		}
	}
	if(dp[n] != n + 1){
		return dp[n];
	}
	return -1;
}
int main(){
	int t; cin>>t;
	dp[0] = 0;
	while(t--){
		int n; cin>>n;
		vector<int> money = {1, 3, 6, 10, 15};
		int ans = 0;
		int resto = 0;
		
		if(n > 100){
			resto = n - 100;
			resto = ceil(resto/15.0);	
		}
		ans = resto;
		n = n - resto*15;

		cout<<ans+ solve(money, n)<<endl;
	}
	
	return 0;
}