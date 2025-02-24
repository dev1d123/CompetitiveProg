#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        multiset<int> m1;
        multiset<int> m2;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            if(x%2 == 0) m1.insert(-x);
            else m2.insert(-x);
        }
        int c = 0;
        int a=0;
        int b=0;
        while(c != n){
            int odd = -1; 
            int even = -1; 
            if(!m1.empty()) even = -(*m1.begin()); 
            if(!m2.empty()) odd = -(*m2.begin());
            if (even >= odd) {
                if (even != -1) a += even;
                if (!m1.empty()) m1.erase(m1.begin());
            } else {
                if (!m2.empty()) m2.erase(m2.begin());
            }
            c++;
            if(c == n) break;
            
            odd = -1; 
            even = -1; 
            if(!m1.empty()) even = -(*m1.begin()); 
            if(!m2.empty()) odd = -(*m2.begin());

            if (odd >= even) {
                if (odd != -1) b += odd;
                if (!m2.empty()) m2.erase(m2.begin());
            } else {
                if (!m1.empty()) m1.erase(m1.begin());
            }
            c++;
        }
        if(a > b){
            cout<<"Alice"<<endl;
        }else if(a < b){
            cout<<"Bob"<<endl;
        }else{
            cout<<"Tie"<<endl;
        }
    }



    return 0;
}