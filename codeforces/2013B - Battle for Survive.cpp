#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		
		for(int i = 0; i < n; i++){
			cin>>arr[i];	
		}
		if(n == 2){
			cout<<arr[1] - arr[0]<<endl;
			continue;
		}else if(n == 3){
			int res = arr[1] - arr[0];
			cout<<arr[2] - res<<endl;
			continue;
		}
		int sum = 0;
		for(int i = 0; i < n - 3; i++){
			sum += arr[i];
		}
		int res = arr[n-2] - sum;
		int res2 = res - arr[n-3];
		int ans = arr[n-1]-res2;
		cout<<ans<<endl;
	}
	
	
	return 0;
}