#include<bits/stdc++.h>
 
 
using namespace std;
#define ll long long 
 
set<int> sqrtDivisor(int n){
    set<int> divisors ;
    for(int i = 1 ; i * i <= n ; i++){ 
        if(!(n % i)){
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }
    return divisors;
}
 
int main () {
    int low, high;
    cin >> low >> high;
    set<int> st = sqrtDivisor(__gcd(low, high));
    
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        auto it = st.upper_bound(b);
        if(it != st.begin() && *(--it) >= a)
            cout << *it << '\n';
        else
            cout << "-1\n" ;
    }
    
    return 0 ;
}