#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int minAnimals = n/4; 
		int res = n - minAnimals*4;
		cout<<res/2 + minAnimals<<endl;
	}
	
	return 0;
}