#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			string s; cin>>s;
			arr[i] = s.length();
		}
		//sort(arr.begin(), arr.end());
		int ans = 0;
		int act = 0;
		for(int num: arr){
			if(act + num > m){
				break;
			}else{
				act += num;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}