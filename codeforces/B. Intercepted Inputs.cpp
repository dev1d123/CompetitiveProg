#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve(const vector<int>& arr, int k) {
    unordered_set<int> seen;

	
    for (int num : arr) {
        if (k % num == 0) {
            int complement = k / num;
            if (seen.count(complement)) {
                return {num, complement};
            }
        }
        seen.insert(num);
    }
    return {0,0}; 
}


int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		auto p = solve(arr, n - 2);
		cout<<p.first<<" "<<p.second<<endl;
	}
	
	return 0;
}