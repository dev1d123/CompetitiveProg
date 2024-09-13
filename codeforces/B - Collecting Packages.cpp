#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<int, int> &a, const pair<int, int> &b){
	if(a.first != b.first){
		return a.first < b.first;
	}
	return a.second < b.second;
}
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<pair<int, int>> waos(n);
		for(int i = 0; i < n; i++){
			int a,b; cin>>a>>b;
			waos[i] = {a,b};
		}
		sort(waos.begin(), waos.end());
		bool res = true;
		int x = 0;
		int y = 0;
		string ans = "";
		for(auto p: waos){
			if(p.first < x || p.second < y){
				res = false;
				break;
			}
			string r = "";
			for(x; x < p.first; x++) r+="R";
			string u = "";
			for(y; y < p.second; y++) u+="U";

			ans += r + u;
		}
		if(res){
			cout<<"YES"<<endl;
			cout<<ans<<endl;
		}else{
			cout<<"NO"<<endl;
		}	
	}
	
	
	return 0;
}