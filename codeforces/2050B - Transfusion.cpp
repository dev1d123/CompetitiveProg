#include <bits/stdc++.h>
#define int long long
using namespace std;
bool waos(vector<int> &arr){
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] != arr[0]){
			return false;
		}
	}
	return true;
}
signed main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		int sum = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			sum += arr[i];
		}
		if(sum%n != 0){
			cout<<"NO"<<endl;
			continue;
		}
		
		//mover al inicio...
		for(int i = n - 2; i >= 1; i--){
			//seleccionar al indice a[i]
			int r = arr[i+1];
			arr[i+1] = 0;
			arr[i-1] += r;
		}
		
		//asegurar el a[i-1]
		int num = sum/n;
		
		for(int i = 1; i < n - 1; i++){
			//seleccionar al indice a[i]
			int res = arr[i-1]-num;
			arr[i-1] = num;
			arr[i+1] += res;
		}
		

		
		//comprobar
		
		if(waos(arr)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		
	}
	
	
	return 0;
}