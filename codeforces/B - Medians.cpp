#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(n == 1){
			cout<<1<<endl<<1<<endl;
			continue;
		}
		
		if(k == 1 || k == n){
			cout<<-1<<endl;
		}else{
			if(k == 2){
				cout<<3<<endl;
				cout<<"1 2 3"<<endl;
			}else if(k == n - 1){
				cout<<3<<endl;
				cout<<"1 "<<n-1<<" "<<n<<endl;
			}else{
				cout<<3<<endl;
				if(k%2 == 0){
					//grupo de 1
					cout<<1<<" "<<k<<" "<<k+1<<endl;

				}else{
					//grupo de 3
					cout<<1<<" "<<k-1<<" "<<k+2<<endl;

				}
			}
		}
		
		
	}
	
	
	
	return 0;
}