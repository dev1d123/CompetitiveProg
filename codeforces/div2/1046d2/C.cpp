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
        int n; cin >> n;
        vector<int> a(n+1);
        for(int i=1; i<=n; i++) cin>>a[i];

        vector<int> dp(n+1, 0);
        unordered_map<int, vector<int>> pos;
        int ans = 0;

        for(int i=1; i<=n; i++){
            int x = a[i];
            pos[x].push_back(i);
            
            int siz = sz(pos[x]);
            if(siz >= x){ //block!gt
                int st = pos[x][siz-x];
                int prev = 0;
                if(st > 1) prev = dp[st - 1];
                dp[i] = max(dp[i], prev + x);
            }
            //si no se usa xd
            if(i > 1) dp[i] = max(dp[i], dp[i-1]);
            ans = max(ans, dp[i]);
        }
        cout<<ans<<endl;
    }
}

