#include <bits/stdc++.h>
using namespace std;

int conv(vector<int> &arr, int n){
	int ans = 0;
	for(int v: arr){
		ans += (v - n) * (v - n);
	}
	return ans;
}
int main(){
	int n; cin>>n;
	vector<int> arr(n);
	for(int i = 0 ; i < n; i++){
		cin>>arr[i];
	}
	int ans = INT_MAX;
	for(int i = -100; i <= 100; i++){
		ans = min(ans, conv(arr, i));
	}
	cout<<ans<<endl;
	
	return 0;
}