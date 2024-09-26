#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
	int low, high;
	stringstream output;
	while(cin>>low>>high){
		if(low == 0 && high == 0) break;
		int a = low/5;
		int b = high/5;
		output<<b - a + 1<<endl;
	}
	cout<<output.str();
	return 0;
}

