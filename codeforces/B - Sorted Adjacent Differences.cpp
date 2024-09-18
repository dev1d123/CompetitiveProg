#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++) cin>>arr[i];
		sort(arr.begin(), arr.end());
		vector<int> ans(n);
		
		if(n%2==0){
			int c = 1;
			int idx = 0;
			int diff = 0;
			for(int i = n/2 - 1; i >= 0; i--){
				int f = arr[i];
				int s = arr[i+c];
				if(idx == 0){
					ans[idx++] = f;
					ans[idx++] = s;
					diff = abs(f - s);
				}else{
					int elem = ans[idx - 1];
					if(diff <= abs(f - elem)) {
						ans[idx++] = f;
						ans[idx++] = s;

					}else{
						ans[idx++] = s;
						ans[idx++] = f;
					}
				}
				c+=2;
			}
		}else{
			ans[0] = arr[n/2];
			int c = 2;
			int idx = 1;
			int diff = 0;
			for(int i = n/2 - 1; i >= 0; i--){
				int f = arr[i];
				int s = arr[i+c];
				int elem = ans[idx - 1];
				if(diff <= abs(f - elem)) {
					ans[idx++] = f;
					ans[idx++] = s;

				}else{
					ans[idx++] = s;
					ans[idx++] = f;
				}
				
				c+=2;
			}
		}
		for(int num: ans) cout<<num<<" ";
		cout<<endl;
 	}
	
	
	
	return 0;
}