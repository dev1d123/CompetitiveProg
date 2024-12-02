#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n%2 == 1 && n < 27){
			cout<<-1<<endl;
			continue;
		}
		
		if(n%2 == 1 & n >= 27){
			//siempre
			vector<int> arr(n, -1);
			arr[0] = 1;
			arr[9] = 1;
			arr[25] = 1;
			arr[26] = 2;
			arr[22] = 2;
			int c = 3;
			int change = 0;
			for(int i = 0; i < n; i++){
				if(arr[i] != -1) continue;
				arr[i] = c;
				change++;
				if(change%2 == 0) c++;
			}
			
			for(int i = 0; i < n; i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;	
			
		}else{
			for(int i = 1; i <= n/2; i++){
				cout<<i<<" "<<i<<" ";
			}
			cout<<endl;	
		}
	}
	
	
	return 0;
}