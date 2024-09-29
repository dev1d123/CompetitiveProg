#include <bits/stdc++.h>
using namespace std;
void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}
int main(){
	fastIO();
	int n; cin>>n;
	map<int, int> mp;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	for(auto p: mp){
		int elem = p.second;
		for(int i = 0; i < elem/2; i++){
			mp[p.first]-=2;
			mp[p.first + 1]++;
		}
	}
	int num = 0;
	for(auto p: mp){
		if(p.second != 0) num++;
	}	
	bool ans = false;
	if(num == 1 || num == 2) ans = true;
	
	if(ans && n != 1) cout<<"Y"<<'\n';
	else cout<<"N"<<'\n';
	
	
	return 0;
}