#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	stringstream output;
	while(n--){
		int a; cin>>a;
		if(a == 1){
			output<<"0.000"<<endl;
		}else{
			output<<fixed<<setprecision(3) << pow(a, 2) - pow(a-2, 2) + pow(a-2, 2) * sqrt(2)<<endl;
		}	
		output<<endl;
	}
	cout<<output.str();
	return 0;
}