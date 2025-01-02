#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	
	vector<int> nodes(n);
	
	vector<int> parent(n);
	
	map<int, bool> deletable;
	for(int i = 0; i < n; i++){
		deletable[i] = true;
 	}
	
	for(int i = 0; i < n; i++){
		int p, c; 
		cin>>p>>c;
			
		if(p != -1){
			p--;
			//el padre de i es p
			parent[i] = p;
			if(c == 0){
				deletable[p] = false;
			}
		}else{
			parent[i] = -1;		
		}
		
		nodes[i] = c;	
		
		if(c == 0){
			deletable[i] = false;
		}
		
	}	
	
	//acceder a todos los nodos, no es necesario eliminar, basta cambiar la referencia del padre!
	//cout<<"Los nodos eliminables son:"<<endl;
	set<int> st;
	
	for(int i = 0; i < n; i++){
		if(deletable[i]) st.insert(i+1);
		//cout<<i+1<<": "<<deletable[i]<<endl;	
	}
	if(st.size() == 0){
		cout<<-1<<endl;
		return 0;
	}
	for(int v: st){
		cout<<v<<" ";
	}
	
	cout<<endl;
	
	
	
	return 0;
}