#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	vector<int> dp(n + 1, -1);
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
		string digits = to_string(i);
		int ans = INT_MAX;
		for(char c: digits){
			int op = c - '0';
			if(op == 0) continue;
			ans = min(ans, dp[i - op] + 1);
		}
		dp[i] = ans;
	}
	cout<<dp[n]<<endl;
	
	return 0;
}