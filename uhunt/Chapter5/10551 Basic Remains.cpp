#include <bits/stdc++.h>
#define int long long
using namespace std;

string toBaseN(int num, int base){
	string ans = "";
	string numerals = "0123456789";
	while(num > 0){
		int res = num%base;
		ans=numerals[res]+ans;
		num/=base;
	}
	if(ans == ""){
		return "0";
	}
	return ans;
}


int toBase10(string &num, int base) {
    int ans = 0;
    int power = 1; 

    for (int i = num.length() - 1; i 	>= 0; i--) {
        ans += (num[i] - '0') * power;
        power *= base;
    }

    return ans;
}
string bigIntegerMod(string &num, int mod) {

    int divisor = mod;
    int temp = 0;
    
    for (int i = 0; i < num.length(); i++) {
        temp = (temp*10 + (num[i] - '0')) % divisor;
    }
    return to_string(temp);
}
int solve(int b, string &p, string &m){
	int mod = toBase10(m, b);
	int c = p.length() - 1;
	int ans = 0;
	 
	for(int i = 0; i < p.length(); i++){
		int powMod = 1;
		for(int j = 1; j <= c; j++){
			powMod *= b;
			powMod%=mod;
		}
		ans += (p[i]-'0') * powMod;
		ans%=mod;
		c--;	
	}
	return ans;
}

signed main(){
	int b;
	string p, m;
	stringstream output;
	while(cin>>b){
		
		if(b == 0){
			break;
		}
		cin>>p>>m;
		int mod = solve(b, p, m);
		
		output<<toBaseN(mod, b)<<endl;
		
	}
	cout<<output.str();
	return 0;
}