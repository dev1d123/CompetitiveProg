#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;

		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		if(n == 1){
			cout<<0<<endl;
			continue;
		}
		int len = 0;
		int act = 0;
		for(int i = 0; i < n - 1; i++){
			if(arr[i] <= arr[i+1]){
				act++;
			}else{
				len = max(act+1, len);
				act = 0;
			}
		}
		len = max(act+1, len);

		cout<<n - len<<endl;
		 
	}
	
	return 0;
}