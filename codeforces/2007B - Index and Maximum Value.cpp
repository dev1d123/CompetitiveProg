#include <iostream>
#include <vector>
using namespace std;

int main(){
	int t; cin>>t;
	while(t--){
		int n, m; cin>>n>>m;
		vector<int> arr(n);
		int maxElem = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			maxElem = max(maxElem, arr[i]);
		}
		vector<int> ans;
		while(m--){
			char op;
			int l, r;
			cin>>op>>l>>r;
			if(op == '+'){
				if(l <= maxElem && maxElem <= r){
					maxElem++;
				}
			}else{
				if(l <= maxElem && maxElem <= r){
					maxElem--;
				}
			}
			ans.push_back(maxElem);
		}
		for(int num: ans){
			cout<<num<<" ";
		}
		cout<<endl;
	}

    return 0;
}
