#include <iostream>
#include <bitset>
#include <cmath>
 
typedef long long ll;
using namespace std;
 
int main(){
  ll t; cin>>t;
  while(t--){
    ll b,c,d;
    cin>>b>>c>>d;
 
    bitset<61> ans;
    ans.set();
    bool fl = true;
 
    for(int i = 0; i < 61; i++){
      ll des = 1LL << i;
      bool b1 = b & des;
      bool b2 = c & des;
      bool b3 = d & des;
 
      if(b1 && !b2 && !b3){
        fl = false; break;
      }else if(b1 && b2 && b3){
        ans.reset(i);
      }else if(!b1 && !b2 && !b3){
        ans.reset(i);
      }else if(!b1 && b2 && b3){
        fl = false; break;
      }
    }
    if(fl){
      cout<<ans.to_ullong()<<endl;
    }else{
      cout<<"-1"<<endl;
    }
 
 
 
 
 
  }
 
}