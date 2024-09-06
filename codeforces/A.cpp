#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int arr[n];
		int sum1 = 0;
		int sum0 = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			if(arr[i] == 1){
				sum1++;
			}
			if(arr[i] == 0){
				sum0++;
			}
		}
		vector<int> ans;
		if(sum1 > sum0){
			int len = sum1;
			if(sum1%2 == 0){
				//mantener todos los 1 (:()
			}else{
				len--;
			}
			for(int i = 0; i < len; i++){	
				ans.push_back(1);
			}
		}else if(sum1 <= sum0){
			int len = sum0;
			for(int i = 0; i < len; i++){	
				ans.push_back(0);
			}

		}
		cout<<(int)ans.size()<<endl;
		for(int num: ans){
			cout<<num<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}