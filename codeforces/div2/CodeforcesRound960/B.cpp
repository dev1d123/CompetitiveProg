#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		
		vector<int> arr(n,-1);
		
		for(int i = y-1; i < x; i++){
			arr[i] = 1;
		}
		
		for(int i = 0; i < n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		
	}
	
	
	return 0;
}

//5 2 1

//1 1 -1 -1 -1 out
 
//1 1 -1 1 -1 ans