#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int arr[2*n];
		for(int i = 0; i < 2*n; i++){
			cin>>arr[i];
		}
		sort(arr, arr + 2*n);
		int pos = n;
		int waos = n/2 + 1;
		cout<<abs(arr[pos-1] - arr[pos])<<endl;
	}
	
	return 0;
}