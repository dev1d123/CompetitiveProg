#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> p;

map<int, int> primeFact(int n){
	map<int, int> mp;
	for(int i = 0; (i < (int)p.size() && p[i]*p[i] <= n); i++){
		while(n%p[i] == 0){
			n/=p[i];
			mp[p[i]]++;	
		}
	}
	if(n!=1){
		mp[n]++;
	}
	return mp;
}       

string solve(int num, int exc){
    map<int, int> all;
    for(int i = num; i > 0; i-=exc){
        map<int, int> pf = primeFact(i);
        for(auto pair: pf){
            int primeFactor = pair.first;
            int exponent = pair.second;
        	all[primeFactor] += exponent;

        }
    }
    int ans = 1;
    for(auto p: all){
    	ans *= (p.second + 1);
		if(ans > 1000000000000000000){
			return "Infinity";
		}
	}
	string ret = to_string(ans); 
	return ret;
}

signed main(){
	

	int limit = 500;
	vector<int> pr(limit + 1, 1);

	pr[0] = pr[1] = 0;
	for(int i = 2; i*i <= limit; i++){
		if(pr[i] == 1){
			for(int j = i*i; j <= limit; j+=i){
				pr[j] = 0;
			}
		}
	}
	for(int i = 2; i <= 500; i++){
		if(pr[i] == 1){
			p.push_back(i);
		}
	}
	int t; cin>>t;
	int c = 1;
	while(t--){
		string s; cin>>s;
		int num = 0, exc= 0;
		for(char c: s){
			if(isdigit(c)){
				num = num * 10 + (c - '0');
			}else if(c == '!'){
				exc++;
			}
		}
		string ans = solve(num, exc);
		cout<<"Case "<<c++<<": "<<ans<<endl;
	}
	return 0;
}