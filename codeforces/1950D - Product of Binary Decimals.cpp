#include <bits/stdc++.h>
using namespace std;
bool contieneCerosUnos(const string& str) {
    for (char c : str) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}
int main(){
	int t; cin>>t;
    vector<int> dec;
    for (int i = 2; i <= 100000; ++i) {
        string num = to_string(i);
        if (contieneCerosUnos(num)) {
            dec.push_back(i);
        }
    }
    reverse(dec.begin(), dec.end());
	while(t--){
		int n; cin>>n;
		while(true){
			bool quit = true;
			for(int num: dec){
				if(n%num == 0){
					n = n/num;
					quit = false;
					break;
				}
			}
			if(quit || n == 1){
				break;
			}
		}
		if(n == 1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}