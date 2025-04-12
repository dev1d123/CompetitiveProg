#include <bits/stdc++.h>
#define int long long 

using namespace std;

signed main(){
	int t; cin>>t;
	while(t--){
		int n, k, x; cin>>n>>k>>x;
		vector<int> arr(n);
		for(auto &x: arr) cin>>x;

		int acc = accumulate(arr.begin(), arr.end(), 0LL);
		
		int q = x/acc;
		if(x%acc == 0){
			q--;
		}
		if(q >= k){
			cout<<"0"<<endl;	
		}else{
			//si se va a poder
			x -= q*acc;
			//x < acc!!!
			int d = 0;
			int sum = 0;
			for(int i = n-1; i >= 0; i--){
				sum += arr[i];
				if(sum >= x) break;
				d++;
			}
			int ans = n*k - d - q*n;
			cout<<ans<<endl;
		}
	}

}
