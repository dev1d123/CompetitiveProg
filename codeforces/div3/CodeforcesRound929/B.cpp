#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int arr[n];
		int sum = 0;
		vector<int> mod1;
		vector<int> mod2;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			if(arr[i]%3 == 1){
				mod1.push_back(arr[i]);
			}
			if(arr[i]%3 == 2){
				mod2.push_back(arr[i]);
			}
			sum+=arr[i];
		}
		sum=sum%3;
		if(sum == 0){
			cout<<0<<endl;
		}else if(sum == 1){
			if((int)mod1.size()>=1){
				cout<<1<<endl;
			}else{
				cout<<2<<endl;
			}
		}else{
			cout<<1<<endl;
		}
	}
	
	return 0;
}