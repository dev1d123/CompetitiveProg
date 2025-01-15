#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int l, r; cin>>l>>r;
		if(l <= 3 && r <= 3){
			cout<<-1<<endl;
			continue;
		}
		if(l != r){
			if(r % 2 == 0){
				cout<<r/2<<" "<<r/2<<endl;
			}else{
				r--;
				cout<<r/2<<" "<<r/2<<endl;
			}
			continue;
		}else{
			bool ans = false;
			int div = -1;
			
			for(int i = 2; i*i <= l; i++){
				if(l%i == 0){
					div = i;
					break;
				}
			}
			if(div == -1){
				cout<<"-1"<<endl;
			}else{
				cout<<div<<" "<<l-div<<endl;
			}
		}
		
		
	}
	
	
	return 0;
}