#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,x,y,z; cin>>n>>x>>y>>z;
	int a = min(x,y); int b = max(x,y);
	if(a < z && z < b) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;


	return 0;	
}
