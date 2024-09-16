#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		int m;
		cin>>m;
		cout<<2<<endl;
		int value1 = m;
		int value2 = m-1;
		for(int i = m-1; i >0; i--){
			cout<<ceil((value1+value2)/2.0)<<" "<<i<<endl;
			value1 = ceil((value1+value2)/2.0);
			value2 = i;
		}
	}
	
	return 0;
}