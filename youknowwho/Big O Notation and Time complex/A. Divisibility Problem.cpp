#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int a,b; cin>>a>>b;
		int div = a/b;
		if(a%b != 0) div++;
		cout<<(div)*b - a<<endl;
	}
	return 0;
}