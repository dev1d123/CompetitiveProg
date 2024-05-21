#include <bits/stdc++.h>
using namespace std;
bool isPerm(vector<int> &arr){
	sort(arr.begin(), arr.end());
	for(int i = 1; i <= arr.size(); i++){
		if(arr[i-1] != i){
			return false;
		}
	}
	return true;
}
int main(){
	int t; cin>>t;
	while(t--){
		int m,s;
		cin>>m>>s;
		vector<int> arr(2000);
		vector<bool> ocuped(2000);
		vector<int> perm;
		for(int i = 1; i <= m; i++){
			cin>>arr[i];
			perm.push_back(arr[i]);
			ocuped[arr[i]] = true;
			
		}
		int sum=0;
		bool ans = false;
		for(int i = 1; i <= 2000; i++){
			//s
			if(ocuped[i] == false){
				sum+=i;
				perm.push_back(i);
			}
			if(sum == s){
				ans = true;
				break;
			}
			if(sum > s){
				break;
			}
		}		
		
		if(ans && isPerm(perm)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	
	
	return 0;
}