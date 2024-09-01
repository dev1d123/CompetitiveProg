#include <bits/stdc++.h>
#define int long long
using namespace std;
set<long long> arr;

string getSuffix(int num) {
    int lastDigit = num % 10;
    int lastTwoDigits = num % 100;

    if (lastTwoDigits == 11 || lastTwoDigits == 12 || lastTwoDigits == 13) {
        return "th";
    }

    switch (lastDigit) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}

void solve(){
	for(int i = 0; i < 32; i++){
		if(pow(7,i) > 2000000000) break;
		
		for(int j = 0; j < 32; j++){
			if(pow(5,j)*pow(7,i) > 2000000000) break;
			
			for(int k = 0; j < 32; k++){
				if(pow(5,j)*pow(7,i)*pow(3,k) > 2000000000) break;
				
				for(int m = 0; m < 32; m++){
					if(pow(5,j)*pow(7,i)*pow(3,k)*pow(2,m) > 2000000000) break;
					
					
					long long num = pow(5,j)*pow(7,i)*pow(3,k)*pow(2,m);
					if(0<num && num <= 2000000000){
						arr.insert(num);
					}
					if(arr.size() == 5842) return;
				}
			}
		}
	}
}
signed main(){
	solve();
	vector<int> waos;
	for(int elem: arr){
		waos.push_back(elem);
	}
	int num; 
	while(cin>>num){
		if(num == 0) break;
		cout<<"The "<<num<<getSuffix(num)<<" humble number is "<<waos[num-1]<<"."<<endl;
	}
	return 0;
}

//2000000000
//2147483647