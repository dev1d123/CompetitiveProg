#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t; cin>>t;
	vector<int> pow2;
	for(int i = 0; i < 31; i++){
		pow2.push_back(1<<i);
	}
	while(t--){
		ll n; cin>>n;
		ll ans = (n)*(n+1)/2;
		for(int num: pow2){
			if(num <= n){
				ans -= 2*num;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}