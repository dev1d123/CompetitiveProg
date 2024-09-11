#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		bool signo;
		int num = 0;
		
		int ans = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];

		}
		for(int i = 0; i < n; ){
			if(arr[i] > 0){
				int num = 0;
				while(i < n){
					if(arr[i] < 0) {
						break;
					}
					num = max(num, arr[i]);
					i++;
				}	
				ans += num;
			}else{
				int num = INT_MAX;
				while(i < n){
					if(arr[i] > 0) {
						break;
					}
					num = min(num, abs(arr[i]));
					i++;
				}	
				ans -= num;			
			}
		}
		cout<<ans<<endl;

	}	
	return 0;
}