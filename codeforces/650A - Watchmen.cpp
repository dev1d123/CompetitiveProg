#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n; cin>>n;
	vector<pair<int, int>> p(n);
	map<int, int> mpx;
	map<int, int> mpy;
	map<pair<int, int>, int> rep;
	for(int i = 0; i < n; i++){
		int a,b; cin>>a>>b;
		p[i] = {a,b};
		rep[{a,b}]++;
		mpx[a]++;
		mpy[b]++;
	}
	int ans = 0;
	for(auto pair: p){
		ans += mpx[pair.first];
		
		if(mpx[pair.first] != 0) ans--;
		
		ans += mpy[pair.second];
		
		if(mpy[pair.second] != 0) ans--;
		
		ans -= (rep[pair]-1);
		rep[pair]--;
		mpx[pair.first]--;
		mpy[pair.second]--;
	}
	cout<<ans<<endl;
	
	
	return 0;
}