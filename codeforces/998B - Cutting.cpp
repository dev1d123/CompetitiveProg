#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, b;
	cin>>n>>b;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	vector<int> opr(n, 0);
	vector<int> epr(n, 0);
	for(int i = 0; i < n; i++){
		if(i == 0){
			if(arr[i]%2 == 0){
				epr[i] = 1;
			}else{
				opr[i] = 1;
			}
		}else{
			epr[i] = epr[i - 1];
			opr[i] = opr[i - 1];
			if(arr[i]%2 == 0){
				epr[i]++;
			}else{
				opr[i]++;
			}
		}
	}
	multiset<int> cut;
	for(int i = 0; i < n - 1; i++){
		if(epr[i] == opr[i]){
			cut.insert(abs(arr[i]-arr[i+1]));
		}
	}

	int ans = 0;
	int total = 0;
	for(int c: cut){
		total += c;
		if(total > b){
			break;
		}
		ans++;
	}
	cout<<ans<<endl;
	
	
	return 0;
}