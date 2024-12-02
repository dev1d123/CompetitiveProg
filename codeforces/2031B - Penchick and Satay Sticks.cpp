#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++) cin>>arr[i];
		
		for(int i = 0; i < n - 1; i++){
			if(arr[i] > arr[i+1] && abs(arr[i] - arr[i+1]) == 1){
				swap(arr[i], arr[i+1]);
			}
		}
		bool fl = true;
		for(int i = 0; i < n-1; i++){
			if(arr[i] > arr[i+1]){
				fl = false;
				break;
			}
		}
		
		if(fl) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	
	
	return 0;
}