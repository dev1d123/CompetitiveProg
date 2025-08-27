#include <bits/stdc++.h>
using namespace std;

struct Tree{
    typedef int T;
    static constexpr T unit = INT_MIN;
    T f(T a, T b) { return max(a, b); }
    vector<T> s; int n;
    Tree(int n = 0, T def = unit): s(2*n, def), n(n) {}
    void update(int pos, T val){
        for(s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos*2], s[pos*2 + 1]);

    }
    T query(int b, int e){
        T ra = unit, rb = unit;
        for(b += n, e += n; b < e; b /= 2, e /= 2){
            if(b%2) ra = f(ra, s[b++]);
            if(e%2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

int main(){
    int n; cin>>n;
    Tree st(n);

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    
    map<int, int> comp;
    set<int> s(a.begin(), a.end());
    int c = 0;
    
    for(int num: s){
        comp[num] = c++;
    }
    int ans = 0;
    
    map<int, int> mp;

    for(int i = 0; i < n; i++){
        int lis = st.query(0, comp[a[i]]);
        
        if(lis == INT_MIN) lis = 1;

        ans = max(ans, lis);

        st.update(comp[a[i]], lis + 1);
    }
    cout<<ans<<endl;
    return 0;
}
