#include <bits/stdc++.h>
using namespace std;

// Macro para imprimir una sola variable
#define DBG_VAR(x) cout << #x << " = " << (x) << endl

// Macro para imprimir un vector
#define DBG_VECTOR(vec)                                      \
    {                                                          \
        cout << #vec << " = [";                                \
        for (size_t i = 0; i < (vec).size(); ++i) {            \
            cout << (vec)[i] << (i + 1 == (vec).size() ? "" : ", "); \
        }                                                      \
        cout << "]" << endl;                                   \
    }
    
#define DBG_MAP(m)                                                \
    {                                                               \
        cout << #m << " = {" << endl;                               \
        for (const auto &[key, value] : (m)) {                      \
            cout << "  [" << key << "] = " << value << "," << endl; \
        }                                                           \
        cout << "}" << endl;                                        \
    }

int main(){
	int t; cin>>t;
	while(t--){
		int n, a , b; 
		cin>>n>>a>>b;
		if((a+b)%2 == 0){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		
	}
	return 0;
}