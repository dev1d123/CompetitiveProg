#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		int numMax = 0;
		int numMin = 51;

		for(int i = 0 ; i < n; i++){
			cin>>arr[i];
			numMax = max(numMax, arr[i]);
			numMin = min(numMin, arr[i]);

		}
		bool asc = true;
		for(int i = 0; i < n-1; i++){
			if(arr[i+1] <arr[i]){
				asc = false;
				break;
			}
		}
		if(!asc){
			if(numMax == arr[n-1] || numMin == arr[0]){
				cout<<1<<endl;
			}else if(numMax == arr[0] && numMin == arr[n-1]){
				cout<<3<<endl;
			}else{
				cout<<2<<endl;
			}
		}else{
			cout<<0<<endl;
		}
	}
}