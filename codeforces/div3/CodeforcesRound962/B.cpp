#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<string> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		
		vector<string> ans(n/k);
		
		int row = 0;
		int col = 0;
		

		for(int i = 0; i < n; i+=k){
			col=0;
			for(int j = 0; j < n; j+=k){
				//cout<<"Index: "<<row<<", "<<col<<endl;
				//cout<<"elem: "<<arr[i][j]<<endl;
				//ans[row][col] = arr[i][j];
				cout<<arr[i][j];
				col++;
			}
			cout<<endl;
			row++;
		}
		
		
	}
	
	
	return 0;
}