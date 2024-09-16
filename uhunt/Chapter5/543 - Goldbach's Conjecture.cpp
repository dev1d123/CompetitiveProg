#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 1000000;
    //Erastotenes cribe 
    vector<int> arr(n + 1, 1);  
    arr[0] = arr[1] = 0; 
    
    for(int i = 2; i * i <= n; i++) {
    	//if i is prime...
        if (arr[i] == 1) {
			//delete all multiples of i 
            for(int j = i * i; j <= n; j += i) {
                arr[j] = 0;  
            }
        }
    }	
	int t; 
	stringstream output;
	while(cin>>t){
		if(t==0) break;
		int ans1 = 0;
		int ans2 = 0;
		for(int i = t - 1; i >= 0; i--){
			if(arr[i] == 1 && arr[t-i] == 1){
				ans1 = t-i;
				ans2 = i;
				break;
			}
		}
		output<<t<<" = "<<ans1<<" + "<<ans2<<endl;
	}
	cout<<output.str();
}