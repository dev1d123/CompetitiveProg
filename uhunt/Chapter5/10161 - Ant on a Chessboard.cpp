#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n;
	stringstream output;
	while(cin>>n){
		if(n == 0){
			break;
		}
		//siguiente cuadrado....
		int rt = sqrt(n);
		
		if(n == pow(rt, 2)){
			if(n%2 == 0){
				output<<rt<<" "<<1<<endl;
			}else{
				output<<1<<" "<<rt<<endl;
			}
			continue;
		}
		int sig = pow(rt + 1, 2);
		int prev = pow(rt,2);
		
		int middle = (prev+1 + sig)/2;
		
		int num = ceil(sqrt(n));
		if(num%2 == 0){
		
			if(n > middle){
				output<<num<<" "<<sig-n+1<<endl;

			}else if( n < middle){
				output<<n-prev<<" "<<num<<endl;	

			}else{
				output<<num<<" "<<num<<endl;
			}
		}else{
			if(n > middle){
				output<<sig-n+1<<" "<<num<<endl;

			}else if( n < middle){
				output<<num<<" "<<n-prev<<endl;	

			}else{
				output<<num<<" "<<num<<endl;
			}
		}
	}
	cout<<output.str();
	return 0;
}