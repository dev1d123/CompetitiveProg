#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void fastIO(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 
}
int solve(int a, int b){
  int ans = 0;
  if(b == 1) return a;
 
  while(a != 0){
    if(b > a){
      ans += a;
      a = 0;
      break;
    }
    int pot = log2(a)/log2(b);
    int res = pow(b, pot);
 
    int div = a/res;
    a -= div*res;
    ans+=div;
  }
  return ans;
}
int main(){
  fastIO();
  int t; cin>>t;
  while(t--){
    int a, b;
    cin>>a>>b;
    int ans = solve(a, b);
    cout<<ans<<'\n';
  }
  return 0;
}