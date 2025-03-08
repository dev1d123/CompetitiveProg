#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int wA = 0, bA = 0, wB = 0, bB = 0;
        int idx = 1;
        bool turnA = false; 
        bool isW = false; 
        wA++;
        int sz = idx + 1;
        int ori = n;

        n--;
        while (n >= 0) {
            /*
            if(turnA) cout<<"Turno de A -> "<<sz<<endl;
            else cout<<"Turno de B -> "<<sz<<endl;
            */
            int l = sz;
            int r = min(ori, sz + idx);
            /*
            cout<<"INI: "<<l<<endl;
            cout<<"FIN: "<<r<<endl;
            */
            int total = r - l + 1; 
            int pares = (r / 2) - ((l - 1) / 2);
            int impares = total - pares; 
            /*
            cout<<"pares: "<<pares<<endl;
            cout<<"impares: "<<impares<<endl;
            */
            if(turnA){
                wA += impares;
                bA += pares;
            }else{
                wB += impares;
                bB += pares;
            }
            sz += (idx + 1);
            idx++;
            isW = !isW; 
            if (idx % 2 == 1) turnA = !turnA; 
            n -= idx;
        }
        
        cout << wA << " " << bA << " " << wB << " " << bB << endl;
    }
    
    return 0;
}
