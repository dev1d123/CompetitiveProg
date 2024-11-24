#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		set<int> tired;
		for(int i = 0; i < n; i++){
			int v; cin>>v;
			tired.insert(v);
		}
		if(tired.size() == 2){
			cout<<"Yes"<<endl;
		}else{
			//verificar si el arreglo es ascendente
			bool fl = true;
			for(int i = 0; i < n - 1; i++){
				if(arr[i] > arr[i + 1]){
					fl = false;
					break;
				}
			}
			if(fl) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}