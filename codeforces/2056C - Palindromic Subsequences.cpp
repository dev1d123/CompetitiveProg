#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		cout<<1<<" ";
		int f = 0;
		int s = 0;
		if(n%2 == 0){
			f = n/2;
			s = f - 1;			
		}else{
			f = s = n/2;
		}
		for(int i = 1; i <= f; i++){
			cout<<i<<" ";
		}
		
		for(int i = 1; i <= s; i++){
			cout<<i<<" ";
		}
		cout<<endl;
		
	}
	
	
	return 0;
}