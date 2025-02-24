#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int v1 = 0;
        int v2 = 0;
        for(int i = 0; i < n; i++){
            int x; cin>>x;
            if(x == 1){
                v1++;
            }else{
                v2++;
            }
        }
        bool ans = false;
        int f = 0;
        while(f <= v1){
            int s = 0;
            while(s <= v2){
                
                int n1 = f + 2*s;
                int n2 = (v1-f) + 2*(v2-s);
                if(n1 == n2){
                    ans = true;
                }
                s++;
            }
            f++;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}