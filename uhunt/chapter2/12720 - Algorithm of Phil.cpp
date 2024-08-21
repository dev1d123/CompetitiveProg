#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1000000007;
vector<int> powModCache;

//full dp :)
void preprocessPowMod(int maxLen) {
    powModCache.resize(maxLen + 1);
    powModCache[0] = 1;  // 2^0 = 1
    for (int i = 1; i <= maxLen; i++) {
        powModCache[i] = (powModCache[i - 1] * 2) % mod;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    preprocessPowMod(100000); 
    
    int n;
    cin >> n;
    stringstream output;
    int count = 1;

    while(n--){
        string A;
        int decimalValue = 0;
        cin >> A;
        int l = A.length();
        int c = 1;

        int idx1 = (l - 1) / 2;  
        int idx2 = l / 2;        

        while (true) {
        	
            if ((l - c) % 2 == 1) {
                if(A[idx1] == '1' && A[idx2] == '1'){
                	decimalValue += powModCache[l - c];
                    decimalValue %= mod;
					c++;	
					decimalValue += powModCache[l - c];
                    decimalValue %= mod;
					c++;
				}else if (A[idx2] == '1' || A[idx1] == '1') {
                	decimalValue += powModCache[l - c];
                    decimalValue %= mod;               
                	c+=2;
				}else{
					c+=2;
				}
				idx1--;
				idx2++;
            } else {
                if (A[idx2] == '1') {
                    decimalValue += powModCache[l - c];
                    decimalValue %= mod;
                }
                idx2++;
                idx1--;
                c++;
            }
            if (idx1 < 0 && idx2 >= l) {
                break;
            }
        }

        output << "Case #" << count << ": " << decimalValue % mod << endl;
        count++;
    }
    cout << output.str();
    return 0;
}

