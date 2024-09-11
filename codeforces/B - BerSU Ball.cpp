#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin>>b[i];
	}
	int m; cin>>m;
	vector<int> g(m);
	for(int i = 0; i < m; i++){
		cin>>g[i];
	}
	
	sort(b.begin(), b.end());
	sort(g.begin(), g.end());
	
	int l = min(m,n);
	int pb = 0;
	int pg = 0;
	int ans = 0;
	while(pb < b.size() && pg < g.size()){
		if(abs(b[pb]-g[pg]) <= 1){
			pb++;
			pg++;
			ans++;
		}else{
			if(b[pb] < g[pg]) pb++;
			else pg++; 
		}
	}
	
	cout<<ans<<endl; 
	
	
	
	return 0;
}