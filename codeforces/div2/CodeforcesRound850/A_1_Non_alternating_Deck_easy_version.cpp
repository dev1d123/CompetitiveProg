#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int ansA = 0, ansB = 0;
        int idx = 1;
        bool turnA = true; 
        
        while (n > 0) {
            if (n >= idx) {
                if (turnA) ansA += idx;
                else ansB += idx;
                n -= idx;
            } else {
                if (turnA) ansA += n;
                else ansB += n;
                break;
            }
            
            if (idx % 2 == 1) turnA = !turnA; 
            idx++;
        }
        
        cout << ansA << " " << ansB << endl;
    }
    
    return 0;
}
