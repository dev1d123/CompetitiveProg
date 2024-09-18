#include <bits/stdc++.h>
#define int long long
using namespace std;
int solve(int num){
	num = abs(num);
	int total = num;
	int maxDiv = -1;
	int ct = 0; //different primes
	
	for(int i = 2; i*i <= num; i++){
		bool fo = false;
		while(num%i == 0){
			num/=i;
			maxDiv = i;
			fo = true;
		}
		if(fo) ct++;
	}
    if (num > 1) {
        maxDiv = num;
        ct++;
    }
    if (ct == 1) return -1;
    return maxDiv;
}
signed main(){
	int num; 
	stringstream output;
	while (cin >> num) {
        if (num == 0) break;
        int ans = solve(num);
        output << ans << endl;
    }
    cout<<output.str();
	return 0;
}