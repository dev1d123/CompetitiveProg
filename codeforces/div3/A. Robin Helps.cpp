#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int ans = 0;
		int money = 0;
		for(int i = 0; i < n; i++){
			if(arr[i] >= k) money += arr[i];
			if(arr[i] == 0 && money > 0){
				money--;
				ans++;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
