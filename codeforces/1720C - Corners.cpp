#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vector<string> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int ones = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				ones += (arr[i][j] - '0');
			}
		}
		int maxCeros = 0;
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < m - 1; j++){
				int res = 0;
	            res += (arr[i][j] == '0');
	            res += (arr[i+1][j] == '0');
	            res += (arr[i][j+1] == '0');
	            res += (arr[i+1][j+1] == '0');
				maxCeros = max(maxCeros, res);
			}
		}
		if(maxCeros == 0){
			cout<<ones-2<<endl;
		}else if(maxCeros == 1){
			cout<<ones-1<<endl;
		}else{
			cout<<ones<<endl;
		}
	}
	
}