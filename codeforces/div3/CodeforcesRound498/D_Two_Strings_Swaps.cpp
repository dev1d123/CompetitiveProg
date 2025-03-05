#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    string a,b;
    cin>>a>>b;

    int ans = 0;
    for (int i = 0; i <= (n - 1) / 2; i++) {
        int f = i;
        int s = n - i - 1;

        char a1 = a[f];
        char a2 = a[s];
        char b1 = b[f];
        char b2 = b[s];
        if(f == s){
            if(a1 != b1) ans++;
        }else{
            if((a1 == a2 && b1 == b2) || (a1 == b2 && b1 == a2) || (a1 == b1 && a2 == b2)){
                continue;
            }
            if(b1 == b2 || a1 == b2 || b1 == a2 || a1 == b1 || a2 == b2){
                ans++;
            }else{
                ans+=2;
            }

        }
    }
    cout<<ans<<endl;


    return 0;
}