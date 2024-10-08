#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
 
void fastIO(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
ll llsqrt(ll x){
  if(x == 0 || x == 1) return x;
 
  ll left = 1, right = x, res = 0;
 
  while(left <= right){
    ll mid = left + (right - left) / 2;
    if(mid <= x/mid){
      res = mid;
      left = mid + 1;
    }else{
      right = mid - 1;
    }
  }
  return res;
}
int main(){
  fastIO();
  int t; cin>>t;
  while(t--){
    ll k;
    cin>>k;
    ll n = 1 + llsqrt(1 + 4LL*k);
    n/=2;
    if(k == n*n - n){
      cout<<n*n-1<<endl;
    }else{
      cout<<n+k<<endl;
    }
  }
  return 0;
}
