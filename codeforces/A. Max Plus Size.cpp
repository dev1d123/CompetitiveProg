#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++) cin>>arr[i];
		
		int maxElem = 0;
		int ans1 = 0;
		for(int i = 0; i < n; i+=2){
			ans1++;
			maxElem = max(maxElem, arr[i]);
		}
		ans1+=maxElem;
		
		maxElem = 0;
		int ans2 = 0;
		for(int i = 1; i < n; i+=2){
			ans2++;
			maxElem = max(maxElem, arr[i]);
		}
		ans2+=maxElem;
		int ans = max(ans1, ans2);
		cout<<ans<<endl;
	}
	
	return 0;
}