#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		int maxE = 0;
		map<int, int> waos;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			waos[arr[i]]++;
		}
		sort(arr.begin(), arr.end());
		bool a = false;	
		for(int i = n-1; i>=0; i--){
			//si el elemento es par, no lo escoges!...si es impar alicia gana
			if(waos[arr[i]]%2 == 1){
				a = true;
				break;
			}	
		}
		if(a){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
			
	}
	return 0;
}