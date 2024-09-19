#include <bits/stdc++.h>
using namespace std;
vector<int>	pr(100001, 1);

int solve(int n){
	if(n == 2) return 1;
	if((n+1)%4 == 0 && pr[n] == 1) return 1;
	if((n-1)%4 == 0 && pr[n] == 1) return -1;
	return 1;
}

int sign(int n){
	int s = 1;
	map<int, int> mp;
	for(int i = 2; i * i <= n; i++){
		bool fo = false;
		while(n%i == 0){
			n /= i;
			mp[i]++;
			fo = true;
		}
		if(fo){
			int v = solve(i);
			if(v == -1 && mp[i]%2 == 1){
				s *= -1;
			}
			//else no hay cambios!!!
		}
	}
	//solo existira este divisor
	if(n > 1){
		s *= solve(n);
	}
	return s;
}



int main(){
	pr[0] = 0;
	pr[1] = 1;
	for(int i = 2; i*i <= 100000; i++){
		if(pr[i] == 1){
			for(int j = i*i; j <= 100000; j+=i){
				pr[j] = 0;
			}	
		}
	}
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		if(n == 2) cout<<'+'<<endl;
		else if((n+1)%4 == 0 && pr[n] == 1) cout<<'+'<<endl;
		else if((n-1)%4 == 0 && pr[n] == 1) cout<<'-'<<endl;
		else{
			int v = sign(n);
			if(v == -1) cout<<'-'<<endl;
			else cout<<'+'<<endl;
		}
	}
	
	return 0;
}