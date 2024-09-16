#include <bits/stdc++.h>
using namespace std;
int main(){
	//erastotenes cribe
	int n = 1299709;
	//int n = 12;
	vector<int> primes(n + 1, 1);
	primes[0] = 0;
	primes[1] = 0;
	
	for(int i = 2; i*i <= n; i++){
		if(primes[i] == 1){
			for(int j = i*i; j <= n; j+=i){
				primes[j] = 0;
			}
		}
	}
	
	vector<int> dp1(n + 1, -1);
	vector<int> dp2(n + 1, -1);
	for(int i = 1; i <= n; i++){
		if(primes[i] == 1) dp1[i] = i;
		else dp1[i] = dp1[i-1];
	}
	for(int i = n; i >= 1; i--){
		if(primes[i] == 1) dp2[i] = i;
		else dp2[i] = dp2[i+1];
	}	
	int num;
	stringstream output;
	while(cin>>num){
		if(num == 0) break;
		if(num == 1) {
			//im tired
			output<<1<<endl;
		}else{
			output<<dp2[num] - dp1[num]<<endl;	
		}
	}
	cout<<output.str();
	//dp with erastotenes cribe
	return 0;
}