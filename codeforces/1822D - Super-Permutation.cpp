#include <bits/stdc++.h>
#define DBG(x) cerr<<#x<<": "<<x<<endl;
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		
		if(n == 1){
			cout<<1<<endl;
		}else if(n%2 != 0){
			cout<<-1<<endl;
		}else{
			cout<<n<<" ";
			int v1 = n-1;
			int v2 = 2;
			for(int i = 1; i < n; i++){
				if(i%2 == 1){
					cout<<v1<<" ";
					v1-=2;
				}else{
					cout<<v2<<" ";
					v2+=2;
				}
			}	
			cout<<endl;
		}
		
		/*
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += arr[i];
			int elem = sum%n + 1;
			cout<<elem<<" - ";
		}
		cout<<endl;
		*/
	}
	
	
	
	
	return 0;
}