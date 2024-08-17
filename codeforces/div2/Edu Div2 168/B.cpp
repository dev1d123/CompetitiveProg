#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int ans = 0;
		vector<string> arr(2);
		for(int i = 0; i < 2; i++){
			cin>>arr[i];
		} 
		
		for(int i = 0; i < 2; i++){
			for(int j = 1; j < n-1; j++){
				if(i == 0){
					if(arr[i][j-1] == '.' && arr[i][j+1] == '.' && arr[i+1][j] == '.' && arr[i+1][j+1] == 'x' && arr[i+1][j-1] == 'x'){
						ans++;	
					}
				}else{
					if(arr[i][j-1] == '.' && arr[i][j+1] == '.' && arr[i-1][j] == '.' && arr[i-1][j+1] == 'x' && arr[i-1][j-1] == 'x'){
						ans++;	
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}