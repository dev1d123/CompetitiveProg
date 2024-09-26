#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> p;

map<int, int> primeDiv(int a){
	map<int, int> mp;
		
	for(int i = 0; (i < (int)p.size() && (p[i]*p[i] <= a)); i++){
		while(a%p[i] == 0){
			a = a/p[i];
			mp[p[i]]++;
		}
	}
	if(a != 1){
		mp[a]++;
	}
	return mp;
}

map<int, int> factPrimeDiv(int n, int target) {
	//solo necesitamos algunos factores primos!!!!! xd xd xd
	map<int, int> mp;
	map<int, int> need = primeDiv(target); //i dont want to create other function
	//legendre formula
    for (auto pair: need) {
    	int p = pair.first;
        int exponent = 0;
        int power = p;
        while (power<=n) {
            exponent += n/power;
            if (power > n / p) break; 
            power *= p;
        }
        mp[p] = exponent;
    }
    return mp;
}

bool divisible(map<int, int> &mp1, map<int, int> &mp2){
	for(auto p: mp2){
		mp2[p.first] = p.second - mp1[p.first];
	}
	for(auto p: mp2){
		if(p.second > 0) return false;
	}
	return true;
}

signed main(){
    int LIMIT = (1 << 31) - 1;
    LIMIT = sqrt(LIMIT);
    vector<bool> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false; 
    for (int i = 2; i*i <= LIMIT; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= LIMIT; i++) {
        if (is_prime[i]) {
            p.push_back(i);
        }
    }
	int a, b;
	while(cin>>a>>b){
		if(b == 0){
			cout<<b<<" divides "<<a<<"!"<<endl;
			continue;
		}
		map<int, int> mp1;
		map<int, int> mp2;
		
		mp1 = factPrimeDiv(a, b);
		
		mp2 = primeDiv(b);

		if(divisible(mp1, mp2)){
			cout<<b<<" divides "<<a<<"!"<<endl;
		}else{
			cout<<b<<" does not divide "<<a<<"!"<<endl;
		}	
		
	}	
	
	return 0;
}