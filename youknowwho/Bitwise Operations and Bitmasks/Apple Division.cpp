#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n; cin>>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) cin>>arr[i];
	
	int ans = INT_MAX;
	for(int mask = 0; mask < (1 << n); mask++){
		int g1 = 0;
		int g2 = 0;
		for(int i = 0; i < n; i++){
			if(mask & (1 << i)){
				g1+=arr[i];
			}else{
				g2+=arr[i];
			}
		}
		ans = min(ans, abs(g1-g2));
		
	}
	cout<<ans<<endl;
	
}