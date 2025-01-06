#include <bits/stdc++.h>
using namespace std;

vector<int> stalinRes(vector<int> &arr) {
    int pos = 0;
    vector<int> res;
    res.push_back(arr[pos]);

    for (int act = 1; act < arr.size(); act++) {
        if (arr[act] >= arr[pos]) {
            res.push_back(arr[act]);
            pos = act; 
        }
    }
    return res;
}

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;	
		
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		//el stalin es despues de eliminar...
		int ans = 0;
		for(int i = 0; i < n; i++){
			int count = 0;
			for(int j = i; j < n; j++){
				if(arr[j] <= arr[i]){
					count++;
				}
			}
			ans = max(ans, count);
		}
		cout<<n - ans<<endl;
		
	}
	
	return 0;
}