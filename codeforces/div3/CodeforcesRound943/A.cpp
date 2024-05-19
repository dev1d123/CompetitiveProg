#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int ans = 0;
		int maxRes = 0;
		for(int i = n - 1; i >= 1; i--){
			maxRes = max(maxRes, __gcd(n, i) + i);
			if(maxRes == __gcd(n, i) + i){
				ans = i;
			}
		}
		cout<<ans<<endl;
	}
}