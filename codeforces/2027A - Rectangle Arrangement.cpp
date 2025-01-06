#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a=0, b=0;
		while(n--){
			int w,h; cin>>w>>h;
			a = max(a, w);
			b = max(b, h);
		}
		cout<<(a+b)*2<<endl;
	}
	
	return 0;
}