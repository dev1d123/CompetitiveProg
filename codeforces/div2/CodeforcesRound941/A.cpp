#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int a, b; cin>>a>>b;
		vector<int>arr(a);
		map<int, int> mp;
		bool can = false;
		for(int i = 0; i < a; i++){
			cin>>arr[i];
			mp[arr[i]]++;
			if(mp[arr[i]] >= b){
				can = true;
			}
		}
		if(can){
			cout<<b-1<<endl;
		}else{
			cout<<a<<endl;
		}	
	}
	
	return 0;
}