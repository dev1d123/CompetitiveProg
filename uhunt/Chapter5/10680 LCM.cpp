#include <bits/stdc++.h>
#define int long long
using namespace std;


map<int, int> primeFact(int n, vector<int> &p){
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

int pot(int a, int b) {
    int res = 1;
    a = a % 1000000000; 
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % 1000000000;
        }
        b = b >> 1;
        a = (a * a) % 1000000000;
    }
    return res%1000000000;
}


void solve(int num, vector<int> &p, vector<int> &dp){
    int ans = 1;
    map<int, int> all;

    for(int i = 1; i <= num; i++){
        map<int, int> pf = primeFact(i, p);
        for(auto pair: pf){
            int primeFactor = pair.first;
            int exponent = pair.second;
            if(all[primeFactor] < exponent){
                int diff = exponent - all[primeFactor];
                all[primeFactor] = exponent;
            	ans = (ans * pot(primeFactor, diff)) % 1000000000;
				
				/*
                for(int j = 0; j < diff; j++){
                    ans = (ans * primeFactor) % 1000000000;
                }
                */
            }
        }
        dp[i] = ans;
    }
}

signed main(){
	
	vector<int> dp(1000001, 0);

	int limit = 1000;
	vector<int> pr(limit + 1, 1);
	vector<int> p;

	pr[0] = pr[1] = 0;
	for(int i = 2; i*i <= limit; i++){
		if(pr[i] == 1){
			for(int j = i*i; j <= limit; j+=i){
				pr[j] = 0;
			}
		}
	}
	for(int i = 2; i <= 1000; i++){
		if(pr[i] == 1){
			p.push_back(i);
		}
	}
	solve(1000000, p, dp);
	
	int n;
	//in my pc the time was 7 seconds...bro wtf
	while(cin>>n){
		if(n == 0){
			break;
		}
		string s = to_string(dp[n]);
		for(int i = s.length() - 1; i >= 0; i--){
			if(s[i] != '0'){
				cout<<s[i]<<endl;
				break;
			}
		}
	}

	return 0;
}