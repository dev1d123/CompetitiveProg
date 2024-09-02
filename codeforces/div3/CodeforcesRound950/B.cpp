#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n, f ,k;
		cin>>n>>f>>k;
		vector<int> arr(n);
		map<int ,int> xd;
		int fav = -1;
		int c = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			xd[arr[i]]++;
			if(i+1 == f){
				fav = arr[i];
			}

		}
		c = xd[fav];
		sort(arr.begin(), arr.end(), greater<int>());
		
		int pos = -1;
		for(int i = 0; i < n; i++){
			if(arr[i] == fav){
				pos = i;
				break;
			} 
		}
		int ipos = pos + 1;
		int fpos = ipos + c - 1;
		if(k < ipos){
			cout<<"NO"<<endl;
		}else if(k < fpos && fpos != ipos){
			cout<<"MAYBE"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}