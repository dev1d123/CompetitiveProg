#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull pot(ull b, ull e){
    const ull LIMIT = ULLONG_MAX; //limite para unsigned long long

    ull res = 1;
    ull act = b;
    while (e > 0) {
    	//instead of res*act > LIMIT      =>     res > LIMIT/act
        if (e % 2 == 1) {
            if (res > LIMIT/act) {
                return -1; 
            }
            res *= act;
        }
        if (e > 1 && act > LIMIT/act) {
            return -1; 
        }

        act *= act;
        e /= 2;
    }

    return res;
}
int main(){
	vector<int> waos(65, 1);
	waos[0] = 0;
	waos[1] = 0;
	for(int i = 0; i*i < waos.size(); i++){
		if(waos[i] == 1){
			for(int j = i*i; j < waos.size(); j+=i){
				waos[j] = 0;
			}
		}
	}
	vector<ull> comp;
	for(int i = 4; i < 65; i++){
		if(waos[i] == 0) comp.push_back(i);
	}

	set<ull> ans;
	
	for(ull i = 2; i <= 1000000; i++){

		if(pot(i, 4) == -1) {
			break;
		}
		
		for(ull num: comp){
			ull value = pot(i, num);
			if(value == -1) break;
			else ans.insert(value);
		}
		
	}
	ans.insert(1);
	for(ull num: ans){
		cout<<num<<endl;
	}
	

	
	return 0;
}