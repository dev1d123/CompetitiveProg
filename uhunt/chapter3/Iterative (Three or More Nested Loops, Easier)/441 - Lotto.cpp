#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	stringstream waos;
	bool start = true;
	while(cin>>n){
		if(n != 0 && !start){
			waos<<"\n";
		}else if(n == 0){
			break;
		}
		
		start = false;
		
		vector<int> arr(n);
		for(int i = 0;  i < n; i++){
			cin>>arr[i];
		}
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				for(int k = j + 1; k < n; k++){
					for(int x = k + 1; x < n; x++){
						for(int y = x + 1; y < n; y++){
							for(int z = y+1; z < n; z++){
								waos<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<" "<<arr[x]<<" "<<arr[y]<<" "<<arr[z]<<endl;
							}
						}
					}
				}
			}
		}
	}
	cout<<waos.str();
	
	return 0;
}