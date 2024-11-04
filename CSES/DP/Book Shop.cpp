#include <bits/stdc++.h>
using namespace std;
int main(){
	int mod = 1e9 + 7;
	int n; cin>>n;
	vector<string> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	vector<vector<int>> dp(n, vector<int>(n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j] == '*') dp[i][j] = -1;
		}
	}	
	if(arr[0][0] != '*') dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j] == '*') continue;
			//si hay alguien arriba
			if(i - 1 >= 0 && dp[i-1][j] != -1) dp[i][j]+=dp[i-1][j]%mod;
			if(j - 1 >= 0 && dp[i][j-1] != -1) dp[i][j]+=dp[i][j-1]%mod;
		}
	}
	
	if(dp[n-1][n-1] <= 0){
		cout<<0<<endl;
	}else{
		cout<<dp[n-1][n-1]%mod<<endl;	
	}
	return 0;
}