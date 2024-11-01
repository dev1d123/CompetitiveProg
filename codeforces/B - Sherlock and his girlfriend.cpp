#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	map<int, int> mpA;
	
	map<int, int> mpB;
	vector<pair<int, int>> ans;
	
	for(int i = 0; i < n; i++){
		cin>>a[i];
		mpA[--a[i]] = i;
	}
	for(int i = 0; i < n; i++){
		cin>>b[i];
		mpB[--b[i]] = i;
	}
	
	for(int i = 0; i < n; i++){
		int pos1 = mpA[i];
		int pos2 = mpB[i];
		ans.push_back({pos2, pos1});
	}
	sort(ans.begin(), ans.end());
	for(auto p: ans){
		cout<<p.second + 1<<" ";
	}
	cout<<endl;
	return 0;
}