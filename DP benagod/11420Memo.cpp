#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
vector<vector<vector<ull>>> memo;

ull ans(int n, int s, int locked){
	if(n == 0 && s == 0) return 1; 
	if(s > n || n < 0 || s < 0) return 0;
	if (memo[n][s][locked] != -1) return memo[n][s][locked];
	ull res = ans(n-1, s-locked, 1) + ans(n-1, s, 0);
	return memo[n][s][locked] = res;
}

int main(){
	int n, s; 
	stringstream output;
	while(cin>>n>>s){
		if(n < 0 && s < 0) break;
		memo.assign(n + 1, vector<vector<ull>>(s + 1, vector<ull>(2, -1)));
		output<<ans(n,s,1)<<endl;		
	}
	cout<<output.str();
	return 0;
}
