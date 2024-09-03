#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k; 
	cin>>n>>k;

	int arr[n];
	map<int, int> waos;
	int len = numeric_limits<int>::max();
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		waos[arr[i]]++;
		len = min(len, arr[i]);
	}


	if(k==0){
		if(len - 1 == 0){
			cout<<-1<<endl;
		}else{
			cout<<len-1<<endl;
		}
		return 0;
	}
	
	
	
    for(auto it = waos.begin(); it != waos.end(); ++it) {
        if(it != waos.begin()) {
            it->second += prev(it)->second;
        }
    }
	
	
	for(auto pair: waos){
		if(pair.second == k){
			cout<<pair.first<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}