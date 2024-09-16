#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        int a, b;
        cin >> a >> b;
		if(a == 1 || b == 1){
			cout<<"Finite"<<endl;
			continue;
		}
		bool ans = false;
		for(int i = 2; i <= min(a,b); i++){
			if(a%i == 0 && b%i == 0){
				cout<<"Infinite"<<endl;
				ans = true;
				break;
			}
		}
		if(!ans){
			cout<<"Finite"<<endl;
		}
    }
    
    return 0;
}