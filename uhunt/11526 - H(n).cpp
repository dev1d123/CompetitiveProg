#include <bits/stdc++.h>
#define int long long
using namespace std;

long long H(long long n){
	long long res = 0;
	long long root = sqrt(n);
	//xd
	if(root == 0){
		return 0;
	}
	for(int i = 1; i <= root; i=i+1 ){
		res = (res + n/i);
	}
	//i cant believe.....instead of n/root I put just root :()
	for(int i = n/root - 1; i >= 1; i--){
		res += i * ((n/i) - (n/(i+1)));
	}
	
	return res;
}

signed main(){
	int n; cin>>n;
	while(n--){
		long long num; cin>>num;
		long long waos = H(num);
		cout<<waos<<endl;

	}
	return 0;
}