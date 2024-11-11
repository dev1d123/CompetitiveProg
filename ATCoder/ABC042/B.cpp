#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, l;
	cin>>n>>l;
	vector<string> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];	
	}
	sort(arr.begin(), arr.end());
	
	string ans = "";
	for(int i = 0; i < n; i++){
		ans += arr[i];
	}
	cout<<ans<<endl;
	return 0;
}