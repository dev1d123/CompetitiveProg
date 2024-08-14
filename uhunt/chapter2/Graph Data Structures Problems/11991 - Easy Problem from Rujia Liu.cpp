#include <bits/stdc++.h>
using namespace std;
int main(){
	stringstream output;
    int n, m;
    while(cin >> n >> m){
		vector<int> arr(n);
		map<pair<int, int>, int> waos; //kth and n -> index
		map<int, int> rep; //to store the rep
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			rep[arr[i]]++;
			int repPrev = rep[arr[i]]; //obtener las repeticiones previas
			auto parsito = make_pair(repPrev, arr[i]);
			waos[parsito] = i+1;
		}
		while(m--){
			int a, b;
			cin>>a>>b;
			auto pairFind = make_pair(a,b);
			output<<waos[pairFind]<<endl;
		}
	}
	cout<<output.str();
	
	
	return 0;
}