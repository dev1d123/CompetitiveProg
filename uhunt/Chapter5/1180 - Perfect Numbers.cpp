#include <bits/stdc++.h>
#define int long long 
using namespace std;

bool isPerfect(int num) {
    if (num <= 1) return false;
    int sumDiv = 0;
    for (int i = 1; i*i <= num; i++) {
        if (num % i == 0) {
            sumDiv += i; 
            if(i != 1 && i != num/i){
            	sumDiv += num/i;
			}
        }
    }
    return sumDiv == num;
}
signed main(){
	int t; cin>>t;
	string s; cin>>s;
	stringstream ss(s);
	vector<int> arr;
	string temp;
	while(getline(ss, temp, ',')){
		arr.push_back(stoi(temp));
	}
	for(int num: arr) {
		//cout<<"NUM: "<<num<<endl;
		//the prune
		if(num >= 18){
			cout<<"No"<<endl;
			continue;
		}
		int pf = pow(2, num - 1) * (pow(2, num) - 1);
		if(isPerfect(pf)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}