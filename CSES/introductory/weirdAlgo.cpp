#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ll n; cin>>n;
    cout<<n<< " ";
    while(n != 1LL){
        if(n&1LL) n = n*3LL + 1LL; 
        else n/=2LL;
        cout<<n<<" ";
    }
    cout<<endl;
}

