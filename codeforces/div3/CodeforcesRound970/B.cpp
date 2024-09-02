#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		string s; cin>>s;
		int root = sqrt(n);
		if(root*root == n){
			int ceros = max(root-2, 0);
			ceros = pow(ceros, 2);
			for(char c: s){
				if(c == '0'){
					ceros--;	
				}
			}
			if(ceros == 0){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}else{
			cout<<"No"<<endl;
		}
		
	}
	
	
	return 0;
}