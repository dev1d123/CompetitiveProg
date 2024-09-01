#include <bits/stdc++.h>
using namespace std;
int main(){
	//precalc
	vector<int> prec;
	for(int i = 0; i < INT_MAX; i++){
		long long xd = pow(i,2);
		if(xd >= INT_MAX){
			break;
		}
		prec.push_back(pow(i,2));
	}
	
	int t; cin>>t;
	int c = 1;
	while(t--){
		int waos; cin>>waos;
		vector<int> arr;
		for(int p: prec){
			int tamd = sqrt(p);
			if(tamd > waos) break;
			
			if(tamd != 0 && waos%tamd == 0){
				if(waos - p > 0){
					arr.push_back(waos - p);
				}
			}
		}
		
		
		cout<<"Case "<<c<<":";
		sort(arr.begin(), arr.end());
		for(int w: arr){
			cout<<" "<<w;
		}
		cout<<endl;
		c++;
	}
	return 0;
}