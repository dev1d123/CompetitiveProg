#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll x, y;
		cin>>x>>y;
		ll a,b;
		cin>>a>>b;
		ll maxV, minV;
		//x = 1 y y = 0
		maxV = max(x,y);
		minV = min(x,y);	
		ll moneyA = 0;
		ll moneyB;
		while(minV != maxV){
			maxV--;
			moneyA+=a;
		}
		if(a <= b/2){
			moneyB = (2*maxV )*a;
		}else{
			moneyB = maxV*b;
		}
		cout<<moneyA + moneyB<<endl;
	}
	return 0;
}