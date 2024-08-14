#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin>>n>>k;
	vector<int> arr(n);
	int price = 0;
	int minD = INT_MAX;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		minD = min(minD, abs(arr[i] - k));
		if(minD == abs(arr[i] - k)){
			price = arr[i];
		}
	}
	cout<<price;
	
	
	return 0;
}