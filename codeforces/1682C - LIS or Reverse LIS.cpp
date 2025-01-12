#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		map<int, int> mp;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			mp[arr[i]]++;
		}
		if(n == 1){
			cout<<1<<endl;
			continue;
		}
		vector<int> pal;
		vector<int> uni;
		for(auto p: mp){
			if(p.second >= 2) pal.push_back(p.first);
			if(p.second == 1) uni.push_back(p.first);
		}		
		sort(pal.begin(), pal.end());
		
		int op1 = 0;
		int op2 = 0;
		
		if(pal.size() >= 1) op1 = pal[0];
		if(pal.size() >= 2) op2 = pal[pal.size() - 1];
		/*
		int ctd1 = 0;
		int ctd2 = 0;
		
		//entre 
		for(int num: uni){
			if(num > op1) ctd1++;
			if(num < op2) ctd2++;
		}
		*/
		int ans = pal.size() + (uni.size()+1)/2;
		cout<<ans<<endl;
	}
	
	
	return 0;
}
