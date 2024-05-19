#include <bits/stdc++.h>
using namespace std;
void solve(int a, int b){
	cout<<min(a,b)<<" "<<max(a,b)<<endl;
}
int main(){
	int t; cin>>t;
	while(t--){
		int a,b; cin>>a>>b;
		solve(a,b);
	}
	
	return 0;
}   