#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> st;
    int n; cin>>n;
    while(n--){
        int x; cin>>x; st.insert(x);
    }
    cout<<st.size();
    return 0;
}
