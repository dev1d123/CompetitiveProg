#include <bits/stdc++.h>
#define int long long
using namespace std;
int ans(int n, int i){
	int num = n/i;
	int las = 1 + (num - 1) * i;
	return (num * (1 + las))/2;
}

vector<int> div(int n){
	vector<int> ret;
	for(int i = 1; i*i <= n; i++){
		if(n%i == 0){
			ret.push_back(i);
			if(i != n/i){
				ret.push_back(n/i);
			}
		}
	}
	return ret;
}
signed main(){
	int n; cin>>n;
	set<int> res;
	vector<int> waos = div(n);
	for(int i: waos){
		if(n%i == 0){
			//sucesion que empieza en 1, de n/i terminos, con rango i
			res.insert(ans(n, i));
		}
	}
	for(int num: res){
		cout<<num<<" ";
	}
	cout<<endl;	
	
	
	return 0;
}