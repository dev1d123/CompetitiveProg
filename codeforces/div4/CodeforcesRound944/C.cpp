#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
        if (a > b) {
            swap(a, b);
        }
		bool c1 = false;
		bool c2 = false;	
		for(int i = a; i <= b; i++){
			i = i%13;
			if(c == i || d == i){
				c1 = true;	
			}
		}
		a += 12;	
		for(int i = b; i <= a; i++){
			i = i%13;
			if(i == 0) continue;
			if(i == a-12) break;
			if(c == i || d == i){
				c2 = true;	
			}
		}
		if(c1 && c2){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}