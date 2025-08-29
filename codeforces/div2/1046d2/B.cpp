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
        int n,k; cin>>n>>k;
        string s; cin>>s;

        int wa = 0, c = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                c++;
                wa = max(wa, c);
            } else {
                c = 0;
            }
        }
        if(k <= wa) {
            cout<<"NO"<<endl;
            continue;
        }
        vector<int> ans(n);
        set<int> st;
        for(int i = 1; i <= n; i++) st.insert(i);

        for(int i = 0; i < n; i++){
            if(s[i] == '1') {
                int num = *st.begin();
                st.erase(num);
                ans[i] = num;
            }
        }
        for(int i = 0; i < n; i++){
            if(ans[i] == 0){
                int num = *st.begin();
                st.erase(num);
                ans[i] = num;
            }
        }
        cout<<"YES"<<endl;
        for(int numero: ans){
            cout<<numero<<" ";
        }
        cout<<endl;
    }

}

