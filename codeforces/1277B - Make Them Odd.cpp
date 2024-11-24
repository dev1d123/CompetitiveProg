#include <bits/stdc++.h>
using namespace std;

pair<int, int> desc(int a){
	int pot = 0;
	while(a%2 == 0){
		a/=2;
		pot++;
	}
	return {pot, a};
}

int main(){
	int t; cin>>t;
	while(t--){
		set<int> st;
		int n; cin>>n;
		for(int i = 0; i < n; i++){
			int v; cin>>v;
			if(v%2 == 0){
				st.insert(v);
			}
		}
		int ans = 0;
		map<int, int> res;
		
		for(int num: st){
			auto w = desc(num);
			res[w.second] = max(res[w.second], w.first);
		}
		for(auto xd: res){
			ans += xd.second;
			
		}
		cout<<ans<<endl;
	}
}