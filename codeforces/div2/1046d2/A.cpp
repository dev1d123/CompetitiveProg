#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define dbg(x) cerr<<#x<<" = " <<(x)<<endl;
#define raya cerr<< "==================================="<<endl;
#define rep(i, a, b) for(autg i = a; i < (b); ++i)
#define sz(x) (int)(x).size()


int main(){
    int t; cin>>t;
    while(t--){
       int a,b,c,d; cin>>a>>b>>c>>d;
       if(c >= a && d >= b) {
            bool f1 = true;
            bool f2 = true;
            double ma = max(a,b);
            double mi = min(a,b);
            int part = ceil(ma/(mi+1));
            if(part >= 3) f1 = false;
            
            ma = max(c-a,d-b);
            mi = min(c-a,d-b);
            part = ceil(ma/(mi+1));
            if(part >= 3) f2 = false;
            
            if(f1 && f2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;

       }else{
           cout<<"NO"<<endl;
       }
    }

}

