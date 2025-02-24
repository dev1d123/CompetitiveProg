#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int w,h,n; cin>>w>>h>>n;
        int a = 0;
        int b = 0;

        while(w%2 == 0){
            w/=2; a++;
        }
        while(h%2 == 0){
            h /= 2;
            b++;
        }
        if(pow(2,a)*pow(2,b) >= n) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}