#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;	
		int total = n;
		for(int i = 0; i < 31; i+=2){
			bool a = n&(1<<i);
			bool b = n&(1<<(i+1));
			if(a != b){
				n = n ^ (1 << i);
				n = n ^ (1 << (i+1));
			}	
		}
		//WTF!!! bruh...
		cout<<n<<endl;
	}
	return 0;
}
