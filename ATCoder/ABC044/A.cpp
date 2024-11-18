#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int N, K, X, Y;
	cin>>N>>K>>X>>Y;
	
	if(N <= K){
		cout<<X*N<<endl;	
	}else{
		int res = N - K;
		cout<<X*K + res*Y<<endl;
	}
	
	
	return 0;
}