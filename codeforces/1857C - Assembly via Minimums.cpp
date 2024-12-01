#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int m = (n*(n-1))/2;
		vector<int> arr(m);
		
		map<int, int> mp;

		for(int i = 0; i < m; i++){
			cin>>arr[i];
			mp[arr[i]]++;
		}
		vector<pair<int, int>> rep;
		for(auto p: mp){
			rep.push_back({p.first, p.second});
		}
		
		sort(rep.begin(), rep.end());
		
		
		vector<int> ans(n, 1e9);
		
		int idx = 0;
		int pos = 1;
		for(auto p: rep){
			int a = 0;
			while(a != p.second){
				ans[idx] = p.first;
				a += n - pos;
				idx++;
				pos++;
			}
		}
		
		for(int nun: ans){
			cout<<nun<<" ";
		}
		cout<<endl;
		
	}
	
	
	return 0;
}