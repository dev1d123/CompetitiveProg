#include <bits/stdc++.h>
using namespace std;
int main(){
	int n = 32000;
	vector<int> primes(n + 1, 1);
	primes[0] = 0; 
	primes[1] = 0;
	for(int i = 2; i*i <= n; i++){
		if(primes[i] == 1){
			for(int j = i*i; j <= n; j += i){
				primes[j] = 0;
			}
		}
	}
	vector<int> waos;
	for(int i = 0; i <= n; i++){
		if(primes[i] == 1) waos.push_back(i);
	}
	vector<vector<int>> ans;
    int size = waos.size();
    
    for (int i = 0; i < size - 2; i++) {

        vector<int> arr = {waos[i]};
        int dist = waos[i + 1] - waos[i];
        for (int j = i + 1; j < size; j++) {
            if (waos[j] - waos[j - 1] == dist) {
                arr.push_back(waos[j]);
            } else {
                break;
            }
        }
        if (arr.size() >= 3) {
            ans.push_back(arr);
            i += arr.size() - 2;
        }
    }
	int a, b;
	stringstream output;
	while(cin>>a>>b){
		
		if(a == 0 && b == 0){
			break;
		}
		int ma = max(a,b); 
		int mi = min(a, b);
		for(vector<int> &v: ans){
			if(mi <= v[0] && ma >= v[v.size() - 1]){
				for(int j = 0; j < v.size(); j++){
					if(j != v.size() - 1) output<<v[j]<<" ";
					else output<<v[j]<<endl;
					
				}
			}
		}
	}
	cout<<output.str();
	return 0;
}