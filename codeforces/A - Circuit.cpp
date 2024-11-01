#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(2*n);
		int c1=0;
		int c0=0;
		
		for(int i = 0; i < 2*n; i++){
			cin>>arr[i];
			if(arr[i] == 0){
				c0++;
			}else{
				c1++;
			}
		}
		int maxL = min(c0, c1);
		int minL = (c0%2 + c1%2)/2;
		cout<<minL<<" "<<maxL<<endl;
	}
	
	
	return 0;
}