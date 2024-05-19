#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n-1);
		for(int i = 0; i < n-1; i++){
			cin>>arr[i];
		}
		vector<int> ans(n);
		//calculate two first values
		//a+2=b;
		int a=0,b=arr[0]+500;
		while(true){
			a = b - arr[0];
			if(b%a == arr[0]){
				break;
			}
			b++;
		}
		
		ans[0] = a;
		ans[1] = b;
		
		for(int i = 1; i < n - 1; i++){
			//last ans -> ans[i], 
			int newElemt = ans[i];
			int a=ans[i],b=arr[i]+ans[i];
			while(true){
				if(b%a == arr[i]){
					break;
				}
				b++;
			}
			ans[i+1] = b;
		}
		for(int num: ans){
			cout<<num<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}