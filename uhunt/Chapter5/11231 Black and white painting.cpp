#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n,m,c;
	stringstream output;
	while(cin>>n>>m>>c){
		if(n == 0 && m == 0 && c == 0){
			break;
		}
		//hallar el subcuadrado
		int a = n-7;
		int b = m-7;
		
		int area = a*b;
		if(area%2 == 0){
			output<<area/2<<endl;
		}else{
			output<<area/2 + c<<endl;
		}
		//n, m, c
	}
	cout<<output.str();
	
	return 0;
}