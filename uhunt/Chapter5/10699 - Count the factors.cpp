#include <bits/stdc++.h>
using namespace std;
int solve(int num, vector<int> &pr){
	map<int, int> mp;
	for(int n: pr){
		while(num%n == 0){
			mp[n]++;
			num /= n;
		}
	}
	return mp.size();
}
int main(){
	
	vector<int> pr (1000001, 1);
	pr[0] = 0;
	pr[1] = 0;
	for(int i = 2; i * i <= 1000000; i++){
		if(pr[i] == 1){
			for(int j = i*i; j <= 1000000; j+=i){
				pr[j] = 0;
			}
		}
	}
	vector<int> primes;
	for(int i = 0; i <= 1000000; i++){
		if(pr[i] == 1){
			primes.push_back(i);
		}
	}
	int n; 
	while(cin>>n){
		if(n == 0) break;
		cout<<n<<" : "<<solve(n, primes)<<endl;
	}
	
	return 0;
}
