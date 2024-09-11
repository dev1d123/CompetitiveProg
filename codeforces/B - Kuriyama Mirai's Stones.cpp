#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n; cin>>n;
	vector<int> dp1(n+1, 0);
	vector<int> dp2(n+1, 0);	
	vector<int> arr(n);
	
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	
	for(int i = 1; i <= n; i++){
		dp1[i] = dp1[i-1] + arr[i-1];
	}
	sort(arr.begin(), arr.end());
	
	for(int i = 1; i <= n; i++){
		dp2[i] = dp2[i-1] + arr[i-1];
	}
	
	int m; cin>>m;
	while(m--){
		int t, l, r;
		cin>>t>>l>>r;
		if(t == 1){
			cout<<dp1[r]-dp1[l-1]<<endl;
		}else{
			cout<<dp2[r]-dp2[l-1]<<endl;
		}
	}
}