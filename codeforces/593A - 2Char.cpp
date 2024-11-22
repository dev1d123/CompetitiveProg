#include <bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	map<char, int> rep;
	vector<char> car;
	vector<string> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		for(char c: arr[i]){
			rep[c]++;
			if(rep[c] == 1){
				car.push_back(c);
			}
		}
	}
	vector<pair<int, int>> ans;
	for(int i = 0; i < car.size(); i++){
		for(int j = i ; j < car.size(); j++){
			//car[i] and car[j]
			
			//minimizar la cantidad de palabras vacias!
			//cout<<"letras usadas: "<<car[i]<<" y "<<car[j]<<endl;
			int partial = 0;
			int blank = 0;
			for(int k = 0; k < n; k++){
				string w = arr[k];
				//cout<<"W: "<<w<<endl;
				int count = 0;
				for(int ch: w){
					//letras a usar!!1
					if(ch != car[i] && ch != car[j]){
						count++;
						break;
					}
				}
				
				if(count != 1){
					partial += w.length();	
				}else{
					blank++;
				}
				//maximizar partial y minimizar blank
				
			}
			//cout<<"blank: "<<blank<<endl;
			//cout<<"partial: "<<partial<<endl;
			ans.push_back({blank, partial});
		}
	}
	pair<int, int> best = {INT_MAX, INT_MIN};
	
	for(auto p: ans){
		if(p.second > best.second || (p.second == best.second && p.first < best.first)){
			best = p;
		}	
	}
	cout<<best.second;
	return 0;
}