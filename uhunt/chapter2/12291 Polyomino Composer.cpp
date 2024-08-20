#include <bits/stdc++.h>
using namespace std;
vector<string> extractMinimalRectangle(const vector<string>& arr) {
    int n = arr.size();
    if (n == 0) return {};

    int m = arr[0].size();
    int min_row = n, max_row = -1;
    int min_col = m, max_col = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == '*') {
                min_row = min(min_row, i);
                max_row = max(max_row, i);
                min_col = min(min_col, j);
                max_col = max(max_col, j);
            }
        }
    }

    vector<string> result;
    for (int i = min_row; i <= max_row; ++i) {
        result.push_back(arr[i].substr(min_col, max_col - min_col + 1));
    }
    return result;
}

bool allDots(const vector<string> &arr, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j] != '.'){
				return false;
			}
		}
	}
	return true;
}
bool compareSubMatrix(const vector<string>& arr, const vector<string>& small, int i, int j) {
    for(int a = 0; a < small.size(); a++) {
        for(int b = 0; b < small[0].size(); b++) {
            if((small[a][b] == '*' && arr[i + a][j + b] == '.')){
                return false;
            }
        }
    }
    return true;
}
int main(){
	int n, m;
	stringstream output;
	while(cin>>n>>m){ 
		if(n == 0 && m == 0){
			break;
		} 
		
		vector<string> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		
		vector<string> small(m);
		for(int i = 0; i < m; i++){
			cin>>small[i];
		}
		//fix the small arr!!!
		small = extractMinimalRectangle(small);
		/*
		cout<<"El arreglo corregido es"<<endl;
		for(string s: small){
			cout<<s<<endl;
		}

		cout<<endl;
				*/
		for(int i = 0; i <= n-small.size(); i++){
			for(int j = 0; j <= n-small[0].size(); j++){
				if(compareSubMatrix(arr, small, i, j)){
					for(int a = 0; a < small.size(); a++){
						for(int b = 0; b < small[0].size(); b++){
							if(small[a][b] == '*'){
								arr[i + a][j + b] = '.';
							}
						}
					}
				}
			}
		}
		//cout<<"Imprimiendo matriz!!!"<<endl;
		if(allDots(arr, n)){
			output<<"1"<<endl;
		}else{
			output<<"0"<<endl;
		}
	}
	cout<<output.str();	
	
	return 0;
}