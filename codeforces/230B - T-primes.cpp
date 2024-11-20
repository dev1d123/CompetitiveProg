#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> sieve(1e6 + 1, 1);

bool esCuadrado(ll n){
	ll raiz = sqrt(n);
	return (raiz*raiz)==n;
}
signed main(){
	sieve[0] = 0;
	sieve[1] = 0;
	for(int i = 2; i*i<= 1e6; i++){
		if(sieve[i] == 1){
			for(int j = i*i; j <= 1e6; j+=i){
				sieve[j] = 0;
			}
		}
	}
	int n; cin>>n;
	vector<ll> arr(n);
	for(ll i = 0; i < n; i++){
		cin>>arr[i];
		if(arr[i] == 1){
			cout<<"NO"<<endl;
			continue;
		}
		if(esCuadrado(arr[i]) && sieve[floor(sqrt(arr[i]))]){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	
	
	return 0;
}