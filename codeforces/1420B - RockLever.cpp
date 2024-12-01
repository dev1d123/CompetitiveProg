#include <bits/stdc++.h>
#define int long long
using namespace std;

int detPot(int a){
	for(int i = 0; i < 32; i++){
		int l = pow(2, i);
		int u = pow(2, i+1);
		if(l <= a && a < u){
			return i;
		}
	}
	cout<<"xd"<<endl;
	return -1;
}
signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<multiset<int>> wao(32, multiset<int>());
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			int pot = detPot(arr[i]);
			wao[pot].insert(arr[i]);
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			int pot = detPot(arr[i]);
			ans += wao[pot].size() - 1;
			auto it = wao[pot].find(arr[i]);
			wao[pot].erase(it);
		}
		cout<<ans<<endl;
		
	}
}