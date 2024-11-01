#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,c; cin>>n>>m>>c;
	vector<int> a(n);
	vector<int> b(m);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < m; i++){
		cin>>b[i];
	}
	
	int idxb = 0;
	for(int i = 0; i <= n - m; i++){	
		idxb = 0;
		for(int j = i; j < i + m; j++){
			a[j] = (a[j] + b[idxb])%c;
			idxb++;
		}
	}	
	for(int num: a){
		cout<<num<<" ";
	}	
	
	return 0;
}