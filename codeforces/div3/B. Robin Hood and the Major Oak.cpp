#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
        int S = (k * (2 * n - k + 1)) / 2;

		if(S%2 == 0){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
