#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		unordered_map<int, int> mp;
		
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			mp[arr[i]]++;
		} 
		if(mp.size() == 1){
			cout<<-1<<endl;
			continue;
		}
        int lst = -1;  
        int ans = n;
        
        for(int i = 0; i < n; i++){
        	if(arr[i] != arr[0]){
        		ans = min(ans, i - lst - 1);
        		lst = i;
			}
		}
		cout<<min(ans, n-lst-1)<<endl;
	}	
	
	return 0;
}