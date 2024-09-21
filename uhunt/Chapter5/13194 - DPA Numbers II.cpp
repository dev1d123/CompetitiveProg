#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> p;

ll solve(ll num){
	ll sumDiv = 1;
	for(ll i = 0; (i < (int)p.size()) && (p[i]*p[i] <= num); i++){
		ll multiplier = p[i], total = 1;
		while(num%p[i] == 0){
			num /= p[i];
			total += multiplier;
			multiplier *= p[i];
		}
		sumDiv *= total;
	}
	if(num != 1) sumDiv *= (num+1);
	return sumDiv;	
}
int main(){
	
	int n = 1000000;
	vector<int> pr(n+1, 1);
	pr[0] = 0;
	pr[1] = 0;
	
	for(int i = 2; i*i <= n; i++){
		if(pr[i] == 1){
			for(int j = i*i; j <= n; j+=i){
				pr[j] = 0;			
			}
		}
	}
	for(int i = 1; i < pr.size(); i++){
		if(pr[i] == 1) p.push_back(i);
	}
	
	int t; cin>>t;
	stringstream output;
	while(t--){
		ll n; cin>>n;
		ll ans = solve(n) - n;
		if(ans > n){
			output<<"abundant\n";
		}else if(ans == n){
			output<<"perfect\n";
		}else{
			output<<"deficient\n";
		}
	}	
	cout<<output.str();
	return 0;
}
