#include <bits/stdc++.h>
#define int long long
using namespace std;
int cuad(int n){
	return n*n;
}

signed main(){
	int n;
	stringstream output;
	while(cin>>n){
		int waos = cuad((n*(n+1))/2);
		output<<waos<<'\n';
	}
	cout<<output.str();
	
	return 0;
}