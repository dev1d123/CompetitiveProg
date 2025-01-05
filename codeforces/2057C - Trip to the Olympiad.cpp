#include <bits/stdc++.h>
using namespace std;
//see, bitwise problems...
void solve(int l, int r) {
    int pot = (31 - __builtin_clz(l ^ r)); //most significative bit, between l and r
    
    int a = l | ((1<<pot) - 1);
    int b = a+1;
    int c = (a==l ? r : l);
    cout<<a<<" "<<b<<" "<<c<<endl;
}
int main(){
	int t; cin>>t;
	while(t--){
		int l, r; cin>>l>>r;
		solve(l, r);
	}
	return 0;
}
//im tired...sorry :(
