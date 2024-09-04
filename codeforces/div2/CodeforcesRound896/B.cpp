#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll minimo(ll a, ll b){
	if(a < b){
		return a;
	}
	return b;
}
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,k,a,b;
		cin>>n>>k>>a>>b;
		vector <pair<ll,ll>> city;
		for(int i = 0; i < n; ++i){
			ll x,y;
			cin>>x>>y;
			city.push_back(make_pair(x,y));
		}	
		ll dist = abs(city[a-1].first - city[b-1].first) + abs(city[a-1].second - city[b-1].second);
		ll dis1 = numeric_limits<ll>::max();
		ll dis2 = numeric_limits<ll>::max();
		ll comp = dis1;
		for(int i = 0; i < k; i++){
			ll distanceStart = abs(city[a-1].first - city[i].first) + abs(city[a-1].second - city[i].second);
			ll distanceEnd = abs(city[b-1].first - city[i].first) + abs(city[b-1].second - city[i].second);
			dis1 = minimo(distanceStart, dis1);
			dis2 = minimo(distanceEnd, dis2);
		}
		ll price; 
		if(k == 0){
			price = dist;
		}else{
			price = dis1 + dis2;	
		}
		ll ans = minimo(price, dist);
		cout<<ans<<endl;
	}
	return 0;
}