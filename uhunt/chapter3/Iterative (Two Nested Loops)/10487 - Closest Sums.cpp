#include <bits/stdc++.h>
using namespace std;
int findMin(vector<int> &s, int elem){
	int diff = numeric_limits<int>::max();
	int res = -1;
	for(int num: s){
		diff = min(diff, abs(elem - num));
		if(diff == abs(elem - num)){
			res = num;
		}
	}
	return res;
}

int main(){
	int n;
	int caso = 1;
	stringstream output;
	while(cin>>n){
		if(n == 0) break;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		vector<int> sum;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				sum.push_back(arr[i] + arr[j]);
			}
		}

		int q; cin>>q;
		output<<"Case "<<caso<<":"<<endl;
		while(q--){
			int query; cin>>query;
			output<<"Closest sum to "<<query<< " is "<<findMin(sum, query)<<"."<<endl;
		}
		caso++;
	}
	cout<<output.str();
	return 0;
}