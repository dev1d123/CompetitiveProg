#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<string> s(n);
		vector<pair<int, int>> p; //index, num
		
		for(int i = 0; i < n; i++){
			cin>>s[i];
			int pos=0;
			for(int j = 0; j < n; j++){
				if(j == i) continue;
				if(i < j){
					//ceros es +, unos es -
					if(s[i][j] == '0'){
						pos++;
					}else{
						pos--;
					}
				}else{
					//ceros es -, unos es +
					if(s[i][j] == '0'){
						pos--;
					}else{
						pos++;
					}
				}
			}
			p.push_back({pos, i+1});
		}
		sort(p.begin(), p.end());
		for(auto pair: p){
			cout<<pair.second<<" ";
		}
		cout<<endl;
		
		
	}
	
	
	return 0;
}