#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int solve(int n, int a, int b, int c){
	//caso base
	if(n == 0) return 0;
	if (n < 0) return INT_MIN;	
	
	if(dp[n] != -1) return dp[n];
	
	int m1 = solve(n - a, a, b, c);
	int m2 = solve(n - b, a, b, c);
	int m3 = solve(n - c, a, b, c);
    int maxCuts = max({m1, m2, m3});
	//siempre va a haber una solucion (garantizado)
    return dp[n] = (maxCuts == INT_MIN ? INT_MIN : maxCuts + 1);
}

int main(){
	int n, a, b, c;
	cin>>n>>a>>b>>c;
	dp.assign(n + 1, -1);

	int ans = solve(n, a, b, c);
	cout<<ans<<endl;
	return 0;
}