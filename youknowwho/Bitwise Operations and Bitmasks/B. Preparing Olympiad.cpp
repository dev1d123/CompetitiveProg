#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,l,r,x;
	cin>>n>>l>>r>>x;
	
	vector<int> a(n);
	
	for(int i = 0; i < n; i++) cin>>a[i];
	
	int ans = 0;
	for(int mask = 0;mask < (1<<n); mask++){
		int sum = 0;
		int ma = 0;
		int mi = INT_MAX;
		for(int i = 0; i < n; i++){
			if(mask & (1<<i)){
				sum+=a[i];
				ma = max(ma, a[i]);
				mi = min(mi, a[i]);
			}
		}
		if(l<=sum && sum<=r && (ma-mi) >= x){
			ans++;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}