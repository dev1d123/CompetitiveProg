#include <bits/stdc++.h>
using namespace std;

void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

void solve(int n){
	static int t = 1;
	if(t == n + 1) return;
	cout<<t<<endl;
	++t;
	solve(n);
}
int main(){
	fastIO();
	int t; cin>>t;
	solve(t);
	return 0;
}