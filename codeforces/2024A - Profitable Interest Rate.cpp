#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int a,b; cin>>a>>b;
		if(a >= b){
			cout<<a<<endl;
		}else{
			int x = b - a;
			int newA = a - x;
			if(newA <= 0){
				cout<<0<<endl;
			}else{
				cout<<newA<<endl;
			}
		}
	}
	
	
	return 0;
}