#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n!=3){
			cout<<"YES"<<endl;
			if(n%2==0){
				for(int i = 0; i < n; i++){
					if(i%2==0){
						cout<<-1<<" ";
					}else{
						cout<<1<<" ";
					}
				}
				cout<<endl;
			}
			else{
				int num = (n-1)/2 - 1;
				for(int i = 0; i < n; i++){
					if(i%2==0){
						cout<<num<<" ";
					}else{
						cout<<-(num+1)<<" ";
					}
				}
				cout<<endl;
			}
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}