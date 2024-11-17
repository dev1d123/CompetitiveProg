#include <bits/stdc++.h>
using namespace std;

bool esCompuesto(int numero) {
    for (int i = 2; i <= std::sqrt(numero); ++i) {
        if (numero % i == 0) return true; 
    }
    return false;
}

int f(int n) {
    for (int m = 2; m < n; m += 2) {
        if (esCompuesto(n + m)) {
            return m;
        }
    }
    return -1; 
}


int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		if(n >= 5){
			int odd = 0;
			for(int i = 1; i <= n; i+=2){
				cout<<i<<" ";
				odd = i;
			}
			int ans = f(odd);
			cout<<ans<<" ";
			
			for(int i = 2; i <= n; i+=2){
				if(i == ans) continue;
				cout<<i<<" ";
			}
			cout<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	
	
	return 0;
}