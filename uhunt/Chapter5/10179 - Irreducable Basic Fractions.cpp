#include <bits/stdc++.h>
using namespace std;
//a little variant from the FelixHalim book...but its the same thing
int eulerPhi(int n){
	int ans = n;
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
			while(n%i == 0){
				n/=i;
			}
			ans -= ans/i;
		}
	}
	if(n > 1){
		ans -= ans/n;	
	}
	return ans;
}

int main(){
	int n;
	while(cin>>n){
		if(n == 0) break;
		int ans = eulerPhi(n);
		/* slow!!!
		for(int i = n-1; i>=0; i--){
			if(__gcd(n, i) == 1) ans++;
		}
		*/
		
		cout<<ans<<endl;
	}
	return 0;
}

