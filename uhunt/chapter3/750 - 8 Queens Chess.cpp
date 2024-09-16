#include <bits/stdc++.h>
using namespace std;

bool valid(vector<int> &arr) {
    unordered_map<int, bool> diagPrincipal, diagSecundaria;
    for (int i = 0; i < 8; i++) {
        int diagP = arr[i] - i; 
        int diagS = arr[i] + i;  
        if (diagPrincipal[diagP] || diagSecundaria[diagS]) {
            return false;
        }
        diagPrincipal[diagP] = true;
        diagSecundaria[diagS] = true;
    }
    return true;  
}


int main(){
	stringstream output;
	ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
	map<pair<int, int>, vector<vector<int>>> ans;
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7};
			do{
				if(arr[i] != j) continue;
				if(valid(arr)){
					ans[{i, j}].push_back(arr);
				}
            } while(next_permutation(arr.begin(), arr.end()));
		}
	}
	int t; cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		output<<"SOLN       COLUMN"<<endl;
		output<<" #      1 2 3 4 5 6 7 8"<<endl;
		output<<endl;
		int n = 1;
		
		vector<vector<int>> arr = ans[{--b, --a}];
		for(int i = 0; i < arr.size(); i++){
			if(n < 10){
				output<<" "<<n<<"     ";
			}else{
				output<<""<<n<<"     ";
			}
			for(int num: arr[i]){
				output<<" "<<num+1;
			}
			output<<endl;

			n++;
		}  	
		if(t != 0) 	output<<endl;
	}
	cout<<output.str();
	return 0;
}