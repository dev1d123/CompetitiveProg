#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t; cin>>t;
	while(t--){
		int a,b,l; cin>>a>>b>>l;
		int x = 0;
		int y = 0;
		int k = 0;
		set<int>ans;
		if(a == 1 && b != 1){
			while((int)pow(b,y) <= l){
				if(l%(int)pow(b,y) == 0){
					ans.insert(l/(int)pow(b,y));
				} 
				y++;
			}
			cout<<(int)(ans.size())<<endl;
			continue;
		}
		if(a != 1 && b == 1){
			while((int)pow(a,x) <= l){
				if(l%(int)pow(a,x) == 0){
					ans.insert(l/(int)pow(a,x));
				} 
				x++;
			}
			cout<<(int)(ans.size())<<endl;
			continue;
		}
		if(a == 1 && b == 1){
			cout<<1<<endl;
			continue;
		}
		while((int)pow(a,x) <= l){
			y = 0;
			while((int)pow(b,y) <= l){
				if(l%((int)pow(a,x)*(int)pow(b,y)) == 0){
					ans.insert(l/(int)(pow(a,x)*(int)pow(b,y)));
				} 
				y++;
			}
			x++;
		}
		cout<<(int)(ans.size())<<endl;
	}
	
	return 0;
}