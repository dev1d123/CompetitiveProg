#include <bits/stdc++.h>
using namespace std;

void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

void solve(int t){
	if(t == 0) return;
	cout<<"I love Recursion"<<'\n';
	solve(--t);
}
int main(){
	fastIO;
	int t; cin>>t;
	solve(t);
	return 0;
}