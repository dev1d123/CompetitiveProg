#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> p;

ll EulerPhi(ll N){
	ll ans = N;
	for(int i = 0; (i < (int)p.size() && (p[i]*p[i] <= N)); i++){
		if(N%p[i] == 0) ans -= ans/p[i];
		while (N%p[i] == 0) N /= p[i];
	}
	if(N != 1) ans -= ans/N;
	return ans;
}
int main(){
	int size = sqrt(2000000) + 1;
	vector<int> pr(size + 1, 1);
	//sieve
	pr[0] = 0;
	pr[1] = 0;
	
	for(int i = 2; i*i <= size; i++){
		if(pr[i] == 1){
			for(int j = i*i; j <= size; j+=i){
				pr[j] = 0;
			}	
		}
	}
	for(int i = 0; i <= size; i++){
		if(pr[i] == 1) p.push_back(i);
	}
	vector<int> dpPhi(2000000 + 1, -1);
	dpPhi[2] = 1; 
	for(int i = 3; i <= 2000000; i++){
		dpPhi[i] = 1 + dpPhi[EulerPhi(i)];
	}
	vector<int> dpSum(2000000 + 1, 0);
	dpSum[2] = 1;
	for(int i = 3; i <= 2000000; i++){
		dpSum[i] = dpPhi[i] + dpSum[i-1];
	}
	int t; cin>>t; 
	while(t--){
		int a,b;
		cin>>a>>b;
		cout<<dpSum[b] - dpSum[a-1]<<endl;
	}
	return 0;
}