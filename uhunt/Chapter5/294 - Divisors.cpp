#include <bits/stdc++.h>
using namespace std;
//:) time is 3 seconds
int getDiv(int n){
	if(n == 1) return 1;
	int ans = 2; //the 1 and the num
	
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
			ans++;
			if(i != 1 && n/i != i){
				ans++;
			}
		}
	}
	return ans;
}
pair<int, int> solve(int l, int u){
	pair<int, int> ans;
	int maxDiv = 0;
	for(int i = l; i <= u; i++){
		//cout<<"El numero "<<i<<" tiene "<<getDiv(i)<<" divisores "<<endl;
		int div = getDiv(i);
		if(div > maxDiv){
			maxDiv = div;
			ans.first = i;
			ans.second = div;
		}
	}
	return ans;
}
int main(){
	int t; cin>>t;
	while(t--){
		int l, u;
		cin>>l>>u;
		pair<int, int> ans = solve(l, u);
		cout<<"Between "<<l<<" and "<<u<<", "<<ans.first<<" has a maximum of "<<ans.second<<" divisors."<<endl;
	}
	
	
	return 0;
}