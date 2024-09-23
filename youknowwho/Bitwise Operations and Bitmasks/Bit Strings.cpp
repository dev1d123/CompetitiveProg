#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int main(){
	int n; cin>>n;
	int ans = 1;
	for(int i = 0; i < n; i++){
		ans *= 2;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}