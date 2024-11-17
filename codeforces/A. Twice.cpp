#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}		
		int ans = 0;
		vector<bool> used(n, false);
		for(int i = 0; i < n; i++){
			if(used[i]) continue;
			used[i] = true;
			for(int j = i + 1; j < n; j++){
				if(arr[i] == arr[j] && used[j] == false){
					ans++;
					used[j] = true;
					break;
				}		
			}
		}
		cout<<ans<<endl;	
	}
	return 0;
}