    #include <bits/stdc++.h>
    using namespace std;
    int main(){
    	int t;cin>>t;
    	vector<int>odd;
    	vector<int>even;
    	for(int i = 0 ; i < t; i++){
    		int v;cin>>v;
    		if(v%2==0){
    			even.push_back(v);
    		}else{
    			odd.push_back(v);
    		}
    	}
    	sort(even.begin(), even.end(), greater<int>());
    	sort(odd.begin(), odd.end(), greater<int>());
    	
    	if(t%2==1){
    		if(abs((int)even.size() - (int)odd.size()) == 1){
    			cout<<0<<endl;
    			return 0;
    		}else{
    			while((int)even.size() >= 0 && (int)odd.size() >= 0){
    				if((int)even.size() > 0){
    					even.erase(even.begin());
    					if((int)odd.size() > 0){
    						odd.erase(odd.begin());
    					}else{
    						break;
    					}
    				}
    				if((int)odd.size() > 0){
    					odd.erase(odd.begin());
    					if((int)even.size() > 0){
    						even.erase(even.begin());
    					}else{
    						break;
    					}
    				}
    			}
    		}
    	}else{
    		if(abs((int)even.size() - (int)odd.size()) == 0){
    			cout<<0<<endl;
    			return 0;
    		}else{
    			while((int)even.size() >= 0 && (int)odd.size() >= 0){
    				if((int)even.size() > 0){
    					even.erase(even.begin());
    					if((int)odd.size() > 0){
    						odd.erase(odd.begin());
    					}else{
    						break;
    					}
    				}
    				if((int)odd.size() > 0){
    					odd.erase(odd.begin());
    					if(even.size() > 0){
    						even.erase(even.begin());
    					}else{
    						break;
    					}
    				}
    			}
    		}
    	}
    	int ans = 0;
    	for(int num: even){
    		ans+=num;
    	}
    	for(int num: odd){
    		ans+=num;
    	}
    	cout<<ans<<endl;
    	return 0;
    }


