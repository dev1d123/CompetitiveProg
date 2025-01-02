#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll r(ll a, ll b){
	return (a+b-1)/b;
}
int main(){
	ll n, m, k, l;
	cin>>n>>m>>k>>l;
	
	if(n < m){
		cout<<-1<<endl;
		return 0;
	}
	//ahora aqui, los regalos van asi -> 1m, 2m, 3m, 4m, 5m....(n)
	//es decir la cantidad de monedas regaladas debe ser mayor en l a k bajo la sucesion planteada.
	

	ll ans = 0;
	ans = r(k+l, m);//ceil((k + l)/(m+0.0));
	if(ans*m > n){
		cout<<-1<<endl;
	}else{
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}