#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> dp(n,0); 
		int arr[n];
		int aux = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int count = 0; //fill from the top.
		for(int i = n-1; i>=0;i--){
			count = max(count, arr[i]);
			if(count > 0){
				dp[i] = 1;
				count--;
			}
		}
		for(int i = 0; i < n; i++){
			cout<<dp[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

