#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	vector<int> arr(n);
	
	int a = INT_MAX;
	int b = INT_MIN;
	
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		if(abs(arr[i])%2 == 1){
			if(arr[i] > 0){
				a = min(a, arr[i]);	
			}else{
				b = max(b, arr[i]);
			}		
		}
	}
	int res = 0;
	
	for(int i = 0; i < n; i++){
		if(arr[i] > 0) res += arr[i];
	}
	if(res%2 == 0){
		if(a != INT_MAX && b != INT_MIN){
			res = max(res - a,res+ b);	
		}else if(a != INT_MAX){
			res = res - a;
		}else{
			res = res + b;
		}
		
	}
	
	cout<<res<<endl;

	
	return 0;
}