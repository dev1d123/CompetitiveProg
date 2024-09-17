#include <bits/stdc++.h>

using namespace std;

int esPosible(int k, int n, vector<int> &pot){
    int op = 0;
    
    for(int num: pot){
        if(num == 0) continue;
        k += num;
        op++;
        if(k >= n) break;
    }
    
    if(k >= n){
        return op;
    }
    return -1; 
}

int main(){
    vector<int> pow2(200001, 0);
    for (int i = 1; i <= 200000; ++i) {
        int elem = i;
        int p = 0;
        while(elem % 2 == 0){
            p++;
            elem /= 2;
        }
        pow2[i] = p;
    }

    int t; 
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<int> arr(n);
        
        int total = 0;
        vector<int> divisors(n);
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            
	        int elem = arr[i];
	        int p = 0;
	        while(elem % 2 == 0){
	            p++;
	            elem /= 2;
	        }
            
            
            divisors[i] = p;
            total += p;
        }
        
        if(total >= n){
            cout << 0 << endl;
        } else {
            vector<int> powerCount;
            for(int i = 1; i <= n; i++){
                powerCount.push_back(pow2[i]);
            }
            sort(powerCount.begin(), powerCount.end(), greater<int>()); 
            int res = esPosible(total, n, powerCount);
            if (res != -1) {
                cout << res << endl; 
            } else {
                cout << -1 << endl;
            }
        }
    }
    
    return 0;
}
