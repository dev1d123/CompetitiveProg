#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	stringstream output;
	while(t--){
		int n, m;
		cin>>n>>m;
		output<<n*m - (n*(n+1))/2<<endl;
	}
	cout<<output.str();
	return 0;
}