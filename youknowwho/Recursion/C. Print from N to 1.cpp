#include <bits/stdc++.h>
using namespace std;
void fastIO(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
}

void solve(int n){
	cout<<n;
	if(n == 1) return;
	else cout<<" ";	
	solve(--n);
}
int main(){
	fastIO();
	int n; cin>>n;
	solve(n);
}