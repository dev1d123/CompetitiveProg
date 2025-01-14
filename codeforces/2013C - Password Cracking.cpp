#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n; 
		string start = "";
        int res;

        bool dire = true;
        
        cout << "? 0" << endl; 
        cin >> res;

        if (res == 0) {
            start = "1";
        } else {
            start = "0";
        }
        if (start.length() == n) {
            cout << "! " << start << endl;
			continue;
		}
		bool ans = false;
		int tr = n;
        while (tr--) {
        	if(dire){
        		int res1, res2;
				cout << "? " << start<<"0"<< endl;
				cin>>res1;
				cout << "? " << start<<"1"<< endl;
				cin>>res2;
				
				if(res1 == 0 && res2 == 0){
					dire = false;
					continue;
				}
				
            	if (res1 == 0) {
                	start += "1";
            	} else {
                	start += "0";
            	}
            	if (start.length() == n) {
	                cout << "! " << start << endl;
	                ans = true;
					break;
				}
            	
			}else{
				int res;
				cout << "? " << "0"<<start << endl;
				cin>>res;
	            if (res == 0) {
	                start = "1"+start;
	            } else {
	                start = "0"+start;
	            }
	            if (start.length() == n) {
	                cout << "! " << start << endl;
	                ans = true;
					break;
	            }
			}
        }
		if(!ans){
			cout<<"! "<<start<<endl;
		}	
	}
	return 0;
}