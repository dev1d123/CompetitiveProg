#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	int sum1 = 0, sum2 = 0;
	int pi = 0, ip = 0;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(a%2 == 1 && b%2 == 0){
			pi++;
		}
		if(a%2 == 0 && b%2 == 1){
			ip++;
		}
		sum1 += a;
		sum2 += b;
	}
	if(sum1%2 == 0 && sum2%2 == 0){
		cout<<0<<endl;
	}else if(sum1%2 != sum2%2){
		cout<<-1<<endl;
	}else{
		if((pi + ip) % 2 == 0 && (pi+ip) != 0){
			cout<<1<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
}