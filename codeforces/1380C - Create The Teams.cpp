#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n, x; cin>>n>>x;
		vector<int> arr(n);
		for(int i = 0; i < n; i++) cin>>arr[i];
		sort(arr.begin(), arr.end(), greater<int>());
		
		int idx=0;
		int act = 0;
		int len = 1;
		int ans = 0;
		while(idx < n){

			while(arr[idx]*len < x){
				len++;
				idx++;
			}
			if(idx >= n) break;
			ans++;
			len = 1;
			idx++;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}