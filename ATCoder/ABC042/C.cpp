#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k; cin>>n>>k;
	
	vector<int> d(10, -1);
	for(int i = 0; i < k; i++){
		int v; cin>>v;
		d[v] = 1;
	} 
	
	string money = to_string(n);
	string ans = "";
	bool isMin = true;
	for(int i = 0; i < (int)money.length(); i++){
		int digit = money[i] - '0';
		
		for(int j = 0; j < 10; j++){
			if(isMin){
				if(d[j] == -1 && j >= digit){
					ans += to_string(j);
					if(j > digit){
						isMin = false;
					}
					break;
				}
			}else{
				if(d[j] == -1){
					ans += to_string(j);
					break;
				}
			}

		}
	}

	int num;
	int digit;
	
	if(ans.length() != 0){
		num = stoi(ans);
	}else{
		num = 0;
		for(int i = 1; i < 10; i++){
			if(d[i] == -1){
				digit = i;
				break;
			}
		}
		ans += to_string(digit);
		num = stoi(ans);
	}
	

	if(num < n){
		int digit;
		for(int i = 0; i < 10; i++){
			if(d[i] == -1){
				digit = i;
				break;
			}
		}	
		while(stoi(ans) < n){
			ans += to_string(digit);
		}
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}

