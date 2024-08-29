#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n; 
	stringstream output;
	while(cin>>n){
		if(n==1){
			output<<"TERM "<<n <<" IS "<<1<<"/"<<1<<endl;
			continue;
		}
		int c = (n-1) * 2;
		int res = sqrt(1+4*c);
		res--;
		
		int term = (res/2);
		term++;
		
		int x;
		int y;
		if(term%2 == 0){
			y = term;
			term /= 2;
			int initial =2*term*term - term + 1;			
			x = 1;
			
			int dif = abs(initial - n);
			y -= dif;
			x += dif;
		}else{
			x = term;
			term /= 2;
			int initial =2*term*term + term + 1;
			y = 1;

			int dif = abs(initial - n);
			y += dif;
			x -= dif;

		}

		output<<"TERM "<<n <<" IS "<<x<<"/"<<y<<endl;
		
	}
	cout<<output.str();
	
	return 0;
}