#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	int c1 = 0;
	int c2 = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin>>arr[n];
		if(arr[n]%2 == 0){
			c1++;
		}else{
			c2++;
		}
		ans = max(c1,c2);
	}
	if(ans == c1){
		cout<<c2<<endl;
	}else{
		cout<<c1<<endl;
	}
	return 0;
}